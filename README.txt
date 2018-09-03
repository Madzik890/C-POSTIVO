============================================================

The POSTIVO is web service, which offers sending letters and
faxes. To using correctly application, You must add your
account to API(https://postivo.pl/apiAccess.php).

============================================================
Added function from the API
============================================================
"dispatch" - now works with only 1 file and 1 recipient
"getDispatchStatus" - displays all shipments/supported 100%
"getBalance" - supported in 100%
"getPrice" - supported in 100%

! NOTICE !
Functions haven't supported additional settings, call in API
"xsd: int config_id", It will be added in near future.
============================================================
Install
============================================================
To compile the POSTIVO, terminal must be opened in super
user (in SUSE "su", in Ubuntu "sudo"). First step after run
console in super mode is run a script called "install.sh",
which should copy 2 libraries to "/lib64", when files will
be copied, application will be compiled.

Example:
cd /home/user/Documents/postivo/
su
sh install.sh

! ATTENTION !
Currently only 64 bit system is supported.
Application was tested on "openSuse 15" and "SLES 12 SP1".
=============================================================
Usage
=============================================================
To run application, should write in console "./postivo".
Now a help message will be displayed, which explains everything
options.

! Arguments !
"-d -dispatch" - create a dispatch
"-gd -gD -getDispatch" - display selected a dispatch
"-gb -gB -getBalance"  - gets from server a basic information
                         about the user
"-gp -gP -getprice"    - receives a price and information
                         about the alleged parcel
==============================================================
