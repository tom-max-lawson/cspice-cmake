/*

-Procedure  ftncls_c ( Close file designated by Fortran unit )

-Abstract

   Close a file designated by a Fortran-style integer logical unit.

-Disclaimer

   THIS SOFTWARE AND ANY RELATED MATERIALS WERE CREATED BY THE
   CALIFORNIA INSTITUTE OF TECHNOLOGY (CALTECH) UNDER A U.S.
   GOVERNMENT CONTRACT WITH THE NATIONAL AERONAUTICS AND SPACE
   ADMINISTRATION (NASA). THE SOFTWARE IS TECHNOLOGY AND SOFTWARE
   PUBLICLY AVAILABLE UNDER U.S. EXPORT LAWS AND IS PROVIDED "AS-IS"
   TO THE RECIPIENT WITHOUT WARRANTY OF ANY KIND, INCLUDING ANY
   WARRANTIES OF PERFORMANCE OR MERCHANTABILITY OR FITNESS FOR A
   PARTICULAR USE OR PURPOSE (AS SET FORTH IN UNITED STATES UCC
   SECTIONS 2312-2313) OR FOR ANY PURPOSE WHATSOEVER, FOR THE
   SOFTWARE AND RELATED MATERIALS, HOWEVER USED.

   IN NO EVENT SHALL CALTECH, ITS JET PROPULSION LABORATORY, OR NASA
   BE LIABLE FOR ANY DAMAGES AND/OR COSTS, INCLUDING, BUT NOT
   LIMITED TO, INCIDENTAL OR CONSEQUENTIAL DAMAGES OF ANY KIND,
   INCLUDING ECONOMIC DAMAGE OR INJURY TO PROPERTY AND LOST PROFITS,
   REGARDLESS OF WHETHER CALTECH, JPL, OR NASA BE ADVISED, HAVE
   REASON TO KNOW, OR, IN FACT, SHALL KNOW OF THE POSSIBILITY.

   RECIPIENT BEARS ALL RISK RELATING TO QUALITY AND PERFORMANCE OF
   THE SOFTWARE AND ANY RELATED MATERIALS, AND AGREES TO INDEMNIFY
   CALTECH AND NASA FOR ALL THIRD-PARTY CLAIMS RESULTING FROM THE
   ACTIONS OF RECIPIENT IN THE USE OF THE SOFTWARE.

-Required_Reading

   None.

-Keywords

   FILES

*/

   #include <cspice/SpiceUsr.h>
   #include <cspice/f2c.h>
   

   void ftncls_c ( SpiceInt unit )

/*

-Brief_I/O

   VARIABLE  I/O  DESCRIPTION
   --------  ---  --------------------------------------------------
   unit       I   Fortran-style logical unit.


-Detailed_Input

   unit           is an integer representing a Fortran logical unit.
   
                  Fortran logical units are integers which in the
                  Fortran language play a role analogous to pointers to
                  FILE structures in C.  In Fortran, when a file is
                  opened and a logical unit is associated with the
                  file, the file and unit are said to be ``connected.''
                  A logical unit, once connected to a file, may be used
                  to refer to the file in Fortran I/O statements.
   
-Detailed_Output

   None.

-Parameters

   None.

-Exceptions

   Error free.

-Files

   The file connnected to unit would normally have been opened via a 
   call to a function generated by running f2c on a Fortran SPICELIB
   routine.  Examples of such functions are
   
     txtopn_
     txtopr_

-Particulars

   This function is provided in order to fully support the file I/O
   interface provided by those CSPICE functions generated by running f2c 
   on Fortran SPICELIB routines.  ftncls_c should be used to close files 
   opened by these functions ONLY IF the files in question would 
   normally be closed, after having been opened by a Fortran program,
   by a Fortran CLOSE statement.  If a file has been opened by a 
   function that has a corresponding "close file" function, the latter
   should be used to close a file.  Examples are the DAF and DAS 
   families of functions:  DAFs are normally closed via dafcls_ and
   DAS files are normally closed via dascls_. 

-Examples

   1) Extract comments from a DAF-based kernel---an SPK file for 
      example---into a text file.
      
         #include <string.h>
         #include <cspice/SpiceUsr.h>
              .
              .
              .
              
         #define   SPK      "my.bsp"
         #define   OUTFILE  "my.txt"
         
         SpiceInt           handle;
         SpiceInt           unit;
         
         /. 
         Open a new text file for write access, obtaining a Fortran 
         logical unit.
         ./
   
         txtopn_  ( OUTFILE, &unit, strlen(OUTFILE) );
         
         /.
         Open the SPK file from which comments are to be extracted.
         ./
         dafopr_  ( SPK, &handle, strlen(SPK) );
         
         /.
         Extract comments into the text file.
         ./
         spcec_   ( &handle, &unit );
         
         /.
         Close the text file.
         ./
         ftncls_c ( unit );



-Restrictions

   1) 
   

-Author_and_Institution

   W.L. Taber      (JPL)
   I.M. Underwood  (JPL)
   E.D. Wright     (JPL)

-Literature_References

   1) Refer to the SPK required reading file for a complete list of
      the NAIF integer ID codes for bodies.

-Version

   -CSPICE Version 1.0.0, 24-MAY-1999 (NJB)

-Index_Entries

   close file designated by Fortran logical unit
   
-&
*/


{ /* Begin  ftncls_c */



   /*
   The following Fortran subroutine was used to generate code
   that closes a logical unit.  The corresponding C code was 
   generated by running f2c (version 19980913) on the Fortran source 
   using the -A (ANSI output) option.
   
   
      SUBROUTINE FORU ( UNIT )
      INTEGER UNIT
      CLOSE ( UNIT )
      END
   
   The output code is included below.  The code has been reformatted
   slightly, and the assignment
   
      cl__1.cunit = *unit;
      
   has been modified so as to not dereference the variable unit, which
   is a SpiceInt rather than a pointer to SpiceInt in this routine.
   
   */
   

   /* 
   System generated locals 
   */
   cllist cl__1;

   /* 
   Builtin functions 
   */
   integer f_clos(cllist *);

   cl__1.cerr  = 0;
   cl__1.cunit = unit;
   cl__1.csta  = 0;
   
   f_clos(&cl__1);


} /* End  ftncls_c*/

