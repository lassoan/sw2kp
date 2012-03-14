Convert password files from SBSH SafeWallet XML export to KeePass XML (2.x) format

Usage: sw2kp input-safewallet-xml-file.xml output-keepass2-xml-file.xml

All SafeWallet fields to KeePass fields. The field names are usually kept
unchanged, with the following exceptions:
  User Name -> UserName
  Login -> UserName
  Web Address -> URL
  Note -> Notes

The VTK (www.vtk.org) library used for XML parsing.
  
  
----- Sample input SafeWallet XML file -----
  
<SafeWallet WalletName="SampleWallet">
  <Folder Caption="Business" Icon="180">
    <Card Caption="My credit card" Icon="12">
      <Property Type="String" Caption="Card">Visa</Property>
      <Property Type="String" Caption="Bank">ABC</Property>
      <Property Type="String" Caption="First Name">John</Property>
      <Property Type="String" Caption="Last Name">Doe</Property>
      <Property Type="String" Caption="Card #">1234567812345678</Property>
      <Property Type="Date" Caption="Expires">2012-03-01 12:00:00 AM</Property>
      <Property Type="Numeric" Caption="CVV2" />
      <Property Type="Password" Caption="PIN">1234</Property>
      <Property Type="String" Caption="If Lost" />
      <Property Type="Note" Caption="Note" />
    </Card>
  </Folder>
  <Folder Caption="Personal" Icon="180">
    <Card Caption="github" Icon="91">
      <Property Type="Web Address" Caption="URL">http://www.github.com</Property>
      <Property Type="String" Caption="Login">myusername</Property>
      <Property Type="Password" Caption="Password">mypassword</Property>
      <Property Type="Note" Caption="Note">This is a note. 
A multi-line note.</Property>
    </Card>
    <Card Caption="Passport" Icon="241">
      <Property Type="String" Caption="Type" />
      <Property Type="String" Caption="Number">AB12345678</Property>
      <Property Type="String" Caption="First Name">John</Property>
      <Property Type="String" Caption="Last Name">Doe</Property>
      <Property Type="Date" Caption="Birth Date">1980-01-16 12:00:00 AM</Property>
      <Property Type="String" Caption="Place" />
      <Property Type="String" Caption="National" />
      <Property Type="Date" Caption="Issued" />
      <Property Type="Date" Caption="Expires" />
      <Property Type="String" Caption="Authority" />
      <Property Type="Note" Caption="Note" />
    </Card>
  </Folder>
</SafeWallet>

----- Sample output KeePass XML (2.x) file -----

<?xml version="1.0" encoding="utf-8"  standalone="yes"?>
<KeePassFile>
<Root>
<Group>
<Group>
<Name>Business</Name>
<Entry>
<String> <Key>Title</Key> <Value>My credit card</Value> </String>
<String> <Key>Card</Key> <Value>Visa</Value> </String>
<String> <Key>Bank</Key> <Value>ABC</Value> </String>
<String> <Key>First Name</Key> <Value>John</Value> </String>
<String> <Key>Last Name</Key> <Value>Doe</Value> </String>
<String> <Key>Card #</Key> <Value>1234567812345678</Value> </String>
<String> <Key>Expires</Key> <Value>2012-03-01 12:00:00 AM</Value> </String>
<String> <Key>CVV2</Key> <Value></Value> </String>
<String> <Key>PIN</Key> <Value>1234</Value> </String>
<String> <Key>If Lost</Key> <Value></Value> </String>
<String> <Key>Notes</Key> <Value></Value> </String>
</Entry>
</Group>
<Group>
<Name>Personal</Name>
<Entry>
<String> <Key>Title</Key> <Value>github</Value> </String>
<String> <Key>URL</Key> <Value>http://www.github.com</Value> </String>
<String> <Key>UserName</Key> <Value>myusername</Value> </String>
<String> <Key>Password</Key> <Value>mypassword</Value> </String>
<String> <Key>Notes</Key> <Value>This is a note. 
A multi-line note.</Value> </String>
</Entry>
<Entry>
<String> <Key>Title</Key> <Value>Passport</Value> </String>
<String> <Key>Type</Key> <Value></Value> </String>
<String> <Key>Number</Key> <Value>AB12345678</Value> </String>
<String> <Key>First Name</Key> <Value>John</Value> </String>
<String> <Key>Last Name</Key> <Value>Doe</Value> </String>
<String> <Key>Birth Date</Key> <Value>1980-01-16 12:00:00 AM</Value> </String>
<String> <Key>Place</Key> <Value></Value> </String>
<String> <Key>National</Key> <Value></Value> </String>
<String> <Key>Issued</Key> <Value></Value> </String>
<String> <Key>Expires</Key> <Value></Value> </String>
<String> <Key>Authority</Key> <Value></Value> </String>
<String> <Key>Notes</Key> <Value></Value> </String>
</Entry>
</Group>
</Group>
</Root>
</KeePassFile>

-------------------------

Copyright (c) 2012, Andras Lasso
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * The name of the contributors may not be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
