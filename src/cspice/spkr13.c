/* spkr13.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include <cspice/f2c.h>

/* $Procedure      SPKR13 ( Read SPK record from segment, type 13 ) */
/* Subroutine */ int spkr13_(integer *handle, doublereal *descr, doublereal *
	et, doublereal *record)
{
    extern /* Subroutine */ int chkin_(char *, ftnlen), spkr09_(integer *, 
	    doublereal *, doublereal *, doublereal *), chkout_(char *, ftnlen)
	    ;
    extern logical return_(void);

/* $ Abstract */

/*     Read a single data record from a type 13 SPK segment. */

/* $ Disclaimer */

/*     THIS SOFTWARE AND ANY RELATED MATERIALS WERE CREATED BY THE */
/*     CALIFORNIA INSTITUTE OF TECHNOLOGY (CALTECH) UNDER A U.S. */
/*     GOVERNMENT CONTRACT WITH THE NATIONAL AERONAUTICS AND SPACE */
/*     ADMINISTRATION (NASA). THE SOFTWARE IS TECHNOLOGY AND SOFTWARE */
/*     PUBLICLY AVAILABLE UNDER U.S. EXPORT LAWS AND IS PROVIDED "AS-IS" */
/*     TO THE RECIPIENT WITHOUT WARRANTY OF ANY KIND, INCLUDING ANY */
/*     WARRANTIES OF PERFORMANCE OR MERCHANTABILITY OR FITNESS FOR A */
/*     PARTICULAR USE OR PURPOSE (AS SET FORTH IN UNITED STATES UCC */
/*     SECTIONS 2312-2313) OR FOR ANY PURPOSE WHATSOEVER, FOR THE */
/*     SOFTWARE AND RELATED MATERIALS, HOWEVER USED. */

/*     IN NO EVENT SHALL CALTECH, ITS JET PROPULSION LABORATORY, OR NASA */
/*     BE LIABLE FOR ANY DAMAGES AND/OR COSTS, INCLUDING, BUT NOT */
/*     LIMITED TO, INCIDENTAL OR CONSEQUENTIAL DAMAGES OF ANY KIND, */
/*     INCLUDING ECONOMIC DAMAGE OR INJURY TO PROPERTY AND LOST PROFITS, */
/*     REGARDLESS OF WHETHER CALTECH, JPL, OR NASA BE ADVISED, HAVE */
/*     REASON TO KNOW, OR, IN FACT, SHALL KNOW OF THE POSSIBILITY. */

/*     RECIPIENT BEARS ALL RISK RELATING TO QUALITY AND PERFORMANCE OF */
/*     THE SOFTWARE AND ANY RELATED MATERIALS, AND AGREES TO INDEMNIFY */
/*     CALTECH AND NASA FOR ALL THIRD-PARTY CLAIMS RESULTING FROM THE */
/*     ACTIONS OF RECIPIENT IN THE USE OF THE SOFTWARE. */

/* $ Required_Reading */

/*     SPK */

/* $ Keywords */

/*     EPHEMERIS */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   Handle of the open SPK file. */
/*     DESCR      I   Descriptor of the segment with the desired record. */
/*     ET         I   Epoch used to identify the desired record. */
/*     RECORD     O   The desired type 13 SPK record. */

/* $ Detailed_Input */

/*     HANDLE         is the handle of the open SPK file which contains */
/*                    the segment of interest. */

/*     DESCR          is the descriptor for a type 13 SPK segment that */
/*                    contains the record of interest. */

/*     ET             is the target epoch used to determine the */
/*                    particular record to be obtained from the SPK */
/*                    segment. */

/* $ Detailed_Output */

/*     RECORD         is the record from the specified segment which, */
/*                    when evaluated at epoch ET, will give the state */
/*                    (position and velocity) of some body, relative */
/*                    to some center, in some inertial reference frame. */

/*                    The structure of the record is as follows: */

/*                       +----------------------+ */
/*                       | number of states (n) | */
/*                       +----------------------+ */
/*                       | state 1 (6 elts.)    | */
/*                       +----------------------+ */
/*                       | state 2 (6 elts.)    | */
/*                       +----------------------+ */
/*                                   . */
/*                                   . */
/*                                   . */
/*                       +----------------------+ */
/*                       | state n (6 elts.)    | */
/*                       +----------------------+ */
/*                       | epochs 1--n          | */
/*                       +----------------------+ */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) It is assumed that the descriptor and handle supplied are */
/*        for a properly constructed type 13 segment. No checks are */
/*        performed to ensure this. */

/*     2) If the input ET value is not within the range specified */
/*        in the segment descriptor, the error SPICE(TIMEOUTOFBOUNDS) */
/*        is signalled. */

/*     3) All other errors are diagnosed by routines in the call tree */
/*        of this routine. */

/* $ Files */

/*     See argument HANDLE. */

/* $ Particulars */

/*     This subroutine will read a single record from a type 13 SPK */
/*     segment. The record read will provide the data necessary to */
/*     compute the state for the body designated by DESCR at epoch */
/*     ET. */

/*     The exact format and structure of a type 13 SPK segment is */
/*     described in the SPK Required Reading. */

/* $ Examples */

/*     The data returned by the SPKRnn routine is in a raw form, taken */
/*     directly from the segment.  As such, it will be not be directly */
/*     useful to a user unless they have a complete understanding of the */
/*     structure of the data type.  Given that understanding, however, */
/*     the SPKRnn routines could be used to "dump" and check segment data */
/*     for a particular epoch, as in the example which follows. */


/*     C */
/*     C     Get a segment applicable to a specified body and epoch. */
/*     C */
/*           CALL SPKSFS ( BODY, ET, HANDLE, DESCR, IDENT, FOUND ) */

/*     C */
/*     C     Look at parts of the descriptor. */
/*     C */
/*           CALL DAFUS ( DESCR, 2, 6, DCD, ICD ) */
/*           CENTER = ICD( 2 ) */
/*           REF    = ICD( 3 ) */
/*           TYPE   = ICD( 4 ) */

/*           IF ( TYPE .EQ. 13 ) THEN */
/*              CALL SPKR13 ( HANDLE, DESCR, ET, RECORD ) */
/*                  . */
/*                  .  Look at the RECORD data. */
/*                  . */
/*           END IF */

/* $ Restrictions */

/*     This subroutine should not be called directly by a casual user. It */
/*     is intended for use by the subroutine SPKPVN, and certain tests */
/*     for error conditions are not performed here, as SPKPVN will have */
/*     already performed them. */

/* $ Literature_References */

/*     NAIF Document 168.0, "S- and P- Kernel (SPK) Specification and */
/*     User's Guide" */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 25-FEB-2000 (NJB) */

/* -& */
/* $ Index_Entries */

/*     read record from type_13 spk segment */

/* -& */

/*     SPICELIB functions */


/*     Standard SPICE error handling. */

    if (return_()) {
	return 0;
    }
    chkin_("SPKR13", (ftnlen)6);

/*     The type 9 reader knows how to obtain a type 13 record. */

    spkr09_(handle, descr, et, record);
    chkout_("SPKR13", (ftnlen)6);
    return 0;
} /* spkr13_ */

