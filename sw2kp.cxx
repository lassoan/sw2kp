#include "vtkXMLDataElement.h"
#include "vtkXMLUtilities.h"
#include "vtkSmartPointer.h"

#include <string>
#include <sstream>

using namespace std;

const char* translateFieldSw2Kp(const char* swCaption)
{
  if (_stricmp(swCaption,"User Name")==0) { return "UserName"; }
  else if (_stricmp(swCaption,"Login")==0) { return "UserName"; }
  else if (_stricmp(swCaption,"Web Address")==0) { return "URL"; }
  else if (_stricmp(swCaption,"Note")==0) { return "Notes"; }
  else return swCaption;  
}

inline string replaceAll( const string& s, const string& f, const string& r ) 
{
  if ( s.empty() || f.empty() || f == r || s.find(f) == string::npos ) {
    return s;
  }
  ostringstream build_it;
  size_t i = 0;
  for ( size_t pos; ( pos = s.find( f, i ) ) != string::npos; ) {
    build_it.write( &s[i], pos - i );
    build_it << r;
    i = pos + f.size();
  }
  if ( i != s.size() ) {
    build_it.write( &s[i], s.size() - i );
  }
  return build_it.str();
}

string encodeToXml(const string &txt)
{
  string xml=replaceAll(txt, "<", "&lt;"); 
  xml=replaceAll(xml, ">", "&gt;");
  xml=replaceAll(xml, "&", "&amp;");
  return xml;
}

string printKeyValue(const string &key, const string &value)
{
  return "<String> <Key>"+encodeToXml(key)+"</Key> <Value>"+encodeToXml(value)+"</Value> </String>\n";
}

int main(int argc, char *argv[])
{
  if (argc<3)
  {
    cerr << "Usage: sw2kp.exe input-safewallet-xml-file.xml output-keepass2-xml-file.xml" << endl;
    return EXIT_FAILURE;
  }
  const char* inputSafeWalletFilename=argv[1];
  const char* outputKeePassFilename=argv[2];

  vtkSmartPointer<vtkXMLDataElement> root=vtkSmartPointer<vtkXMLDataElement>::Take(
    vtkXMLUtilities::ReadElementFromFile(inputSafeWalletFilename));
  
  ofstream outFile; 
  outFile.open(outputKeePassFilename);	
  outFile << "<?xml version=\"1.0\" encoding=\"utf-8\"  standalone=\"yes\"?>" << endl;
  outFile << "<KeePassFile>" << endl;
  outFile << "<Root>" << endl;
  outFile << "<Group>" << endl;
  for (int folderElemIndex=0; folderElemIndex<root->GetNumberOfNestedElements(); folderElemIndex++)
  {
    vtkXMLDataElement* folderElem=root->GetNestedElement(folderElemIndex);
    outFile << "<Group>" << endl;
    outFile << "<Name>" << folderElem->GetAttribute("Caption") << "</Name>" << endl;
    for (int cardElemIndex=0; cardElemIndex<folderElem->GetNumberOfNestedElements(); cardElemIndex++)
    {
      vtkXMLDataElement* cardElem=folderElem->GetNestedElement(cardElemIndex);
      outFile << "<Entry>" << endl;
      outFile << printKeyValue("Title",cardElem->GetAttribute("Caption"));
      for (int propertyElemIndex=0; propertyElemIndex<cardElem->GetNumberOfNestedElements(); propertyElemIndex++)
      {
        vtkXMLDataElement* propertyElem=cardElem->GetNestedElement(propertyElemIndex);
        const char* caption=propertyElem->GetAttribute("Caption");
        outFile << printKeyValue(translateFieldSw2Kp(caption),propertyElem->GetCharacterData());
      }
      outFile << "</Entry>" << endl;
    }
    outFile << "</Group>" << endl;
  }
  outFile << "</Group>" << endl;
  outFile << "</Root>" << endl;
  outFile << "</KeePassFile>" << endl;

  outFile.close(); 

  return EXIT_SUCCESS;
}
