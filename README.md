# description

a hwid grabber made for project based learning purposes

# features

**HWID MODULES**
* retrieves your hard drive serial number
* retrieves your motherboard serial number
* retrieves your computer uuid
* retrieves your processor iD 
* retrieves your boot uuid

**SECURITY PRACTICES**
* xorstr string encryption
* use of local variables

# installation

**step 1** - click on the green ***"code"*** dropdown button and click ***"download zip"***

**step 2** - right click on the hwid-grabber-main.zip file and click ***"extract all"***

**step 3** - open the ***"hwid-grabber-main"*** folder and skid the code into ur project

**step 4** - in the top left of visual studio go to `Project` -> `Properties` -> `General` -> `C++ language standard` -> `/std:c++17`.

**step 5** - while in the project properties page go to `Properties` -> `Advanced` -> `Character Set` -> `Use Multi-Byte Character Set`.

**step 6** - exit out of the project properties page and compile `Ctrl + B`.

# error codes

as part of my "project based learning" journey, i decided to approach a broad amount of subjects regardless of their necessity, one of them being for absolutely no reason other than i was bored, error code structuring!!! for this project i decided to use a hierarchical structure following a consistent format... very exciting stuff! this also happens to be a perfect guideline for anyone who wants to skid this and sell it!

**error code** 1.xx - (MOTHERBOARD SERIAL NUMBER ERRORS)
   * **error code 1.11** - _failed to convert motherboard serial number to string_
   * **error code 1.22** - _failed to create system uuid_

**error code** 2.xx - (USN JOURNAL VOLUME ID ERRORS)
   * **error code 2.11** - _FindFirstVolumeA failed with error code_
   * **error code 2.22** - _CreateFileA failed with error code_
   * **error code 2.33** - _DeviceIoControl failed with error code_
   * **error code 2.44** - _unable to open output file_

**error code** 3.xx - (PROCESSOR ID ERRORS)
   * **error code 3.11** - _failed to open output file_

**error code** 3.xx - (BOOT UUID ERRORS)
   * **error code 4.11** - _failed to initialize COM library_
   * **error code 4.22** - _failed to initialize security_
   * **error code 4.33** - _failed to create IWbemLocator object_
   * **error code 4.44** - _failed to connect to ROOT\\CIMV2 namespace_
   * **error code 4.55** - _failed to set proxy blanket on IWbemServices object_
   * **error code 4.66** - _failed to execute WQL query_

**error code** 4.xx - (HARD DRIVE SERIAL NUMBER ERRORS)
  * **error code 5.11** - _error getting volume information for drive_

## MOTHERBOARD SERIAL NUMBER ERRORS
  ### how to fix error code 1.11 -  _failed to convert motherboard serial number to string_

1. fuck you
2. fix it yourself prick
3. figure it out yourself asshole

  ### how to fix error code 1.22 - _failed to create system uuid_

1. figure it out yourself asshole
2. fix it yourself prick
3. fuck you

## PROCESSOR ID ERRORS
  ### how to fix error code 2.11 - failed to open output file.

1. figure it out yourself asshole
2. fuck you
3. fix it yourself prick

## BOOT UUID ERRORS
  ### how to fix error code 3.11 - failed to initialize COM library

1. figure it out yourself asshole
2. fuck you
3. fix it yourself prick

  ### how to fix error code 3.22 - failed to initialize security

1. figure it out yourself asshole
2. fix it yourself prick
3. fuck you

  ### how to fix error code 3.33 -  failed to create IWbemLocator object

1. fuck you
2. fix it yourself prick
3. figure it out yourself asshole

  ### how to fix error code 3.44 - failed to connect to ROOT\\CIMV2 namespace

1. figure it out yourself asshole
2. fuck you
3. fix it yourself prick


  ### how to fix error code 3.55 -  failed to set proxy blanket on IWbemServices object
1. figure it out yourself asshole
2. fix it yourself prick
3. fuck you

  ### how to fix error code 3.66 - failed to execute WQL query
1. fuck you
2. fix it yourself prick
3. figure it out yourself asshole

## BOOT UUID ERRORS
  ### how to fix error code 4.11 - error getting volume information for drive

1. figure it out yourself asshole
2. fix it yourself prick
3. fuck you
