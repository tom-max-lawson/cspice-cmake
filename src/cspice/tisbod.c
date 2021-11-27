/* tisbod.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include <cspice/f2c.h>

/* Table of constant values */

static integer c__157 = 157;
static integer c__2 = 2;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c__200 = 200;
static integer c__100 = 100;

/* $Procedure      TISBOD ( Transformation, inertial state to bodyfixed ) */
/* Subroutine */ int tisbod_(char *ref, integer *body, doublereal *et, 
	doublereal *tsipm, ftnlen ref_len)
{
    /* Initialized data */

    static logical first = TRUE_;
    static logical found = FALSE_;

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1;

    /* Builtin functions */
    integer s_rnge(char *, integer, char *, integer);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_dnnt(doublereal *);
    double sin(doublereal), cos(doublereal), d_mod(doublereal *, doublereal *)
	    ;

    /* Local variables */
    static doublereal dphi;
    static integer cent;
    static char item[32];
    static doublereal tipm[9]	/* was [3][3] */;
    extern /* Subroutine */ int zzhsiadd_(integer *, integer *, integer *, 
	    integer *, integer *, logical *), zzhsichk_(integer *, integer *, 
	    integer *, integer *, integer *);
    extern integer zzbodbry_(integer *);
    extern /* Subroutine */ int zzhsiini_(integer *, integer *, integer *), 
	    zzpctrck_(integer *, logical *), zzhsiavl_(integer *, integer *);
    static doublereal d__;
    extern /* Subroutine */ int zzctruin_(integer *);
    static integer i__, j;
    static doublereal dcoef[3], t, w;
    extern /* Subroutine */ int etcal_(doublereal *, char *, ftnlen);
    static doublereal delta;
    static integer refid, avail;
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    static doublereal epoch, rcoef[3], tcoef[200]	/* was [2][100] */;
    static integer pcref;
    static doublereal wcoef[3];
    extern /* Subroutine */ int errch_(char *, char *, ftnlen, ftnlen);
    static doublereal theta;
    extern /* Subroutine */ int vpack_(doublereal *, doublereal *, doublereal 
	    *, doublereal *), moved_(doublereal *, integer *, doublereal *), 
	    repmi_(char *, char *, integer *, char *, ftnlen, ftnlen, ftnlen);
    static doublereal dtipm[9]	/* was [3][3] */;
    extern /* Subroutine */ int errdp_(char *, doublereal *, ftnlen);
    static doublereal costh[100];
    extern doublereal vdotg_(doublereal *, doublereal *, integer *);
    static char dtype[1];
    static doublereal sinth[100], xtipm[9]	/* was [3][3] */;
    extern doublereal twopi_(void);
    static integer j2code;
    static doublereal req2pc[9]	/* was [3][3] */, ac[100];
    extern /* Subroutine */ int eul2xf_(doublereal *, integer *, integer *, 
	    integer *, doublereal *);
    static doublereal dc[100];
    static integer na, nd;
    static doublereal ra;
    extern logical failed_(void);
    static doublereal bdcoef[471]	/* was [3][157] */;
    static integer at;
    static doublereal wc[100], dw;
    extern logical bodfnd_(integer *, char *, ftnlen);
    static doublereal ddelta;
    static integer bidids[157];
    static doublereal brcoef[471]	/* was [3][157] */;
    static integer bpcref[157], frcode;
    extern doublereal halfpi_(void);
    static doublereal bpckep[157], pckepc;
    static integer nw;
    static doublereal btcoef[31400]	/* was [2][100][157] */, bwcoef[471]	
	    /* was [3][157] */, dtheta, pckref;
    static integer bidpol[163], bnpair[157];
    extern /* Subroutine */ int pckmat_(integer *, doublereal *, integer *, 
	    doublereal *, logical *);
    static integer bidlst[157];
    static logical update;
    static integer ntheta;
    static doublereal dcosth[100];
    static integer reqref;
    static doublereal dsinth[100], tmpepc;
    static char fixfrm[32], errmsg[1840];
    static doublereal eulsta[6];
    static integer npairs;
    extern /* Subroutine */ int irfnum_(char *, integer *, ftnlen), dtpool_(
	    char *, logical *, integer *, char *, ftnlen, ftnlen);
    static doublereal xdtipm[9]	/* was [3][3] */, costmp;
    extern /* Subroutine */ int ccifrm_(integer *, integer *, integer *, char 
	    *, integer *, logical *, ftnlen), setmsg_(char *, ftnlen);
    static integer pulctr[2];
    static doublereal sintmp;
    extern /* Subroutine */ int suffix_(char *, integer *, char *, ftnlen, 
	    ftnlen), errint_(char *, integer *, ftnlen), sigerr_(char *, 
	    ftnlen);
    extern logical return_(void);
    extern /* Subroutine */ int chkout_(char *, ftnlen), gdpool_(char *, 
	    integer *, integer *, integer *, doublereal *, logical *, ftnlen);
    static char timstr[35];
    extern /* Subroutine */ int cleard_(integer *, doublereal *), bodvcd_(
	    integer *, char *, integer *, integer *, doublereal *, ftnlen), 
	    irfrot_(integer *, integer *, doublereal *);
    static doublereal bac[15700]	/* was [100][157] */, bdc[15700]	
	    /* was [100][157] */;
    extern doublereal j2000_(void);
    static doublereal dec;
    static integer bna[157], bnd[157];
    static doublereal dra;
    static integer dim;
    static doublereal bwc[15700]	/* was [100][157] */, phi;
    extern doublereal rpd_(void), spd_(void);
    static integer bnw[157];
    static logical new__;
    extern /* Subroutine */ int mxm_(doublereal *, doublereal *, doublereal *)
	    ;
    static doublereal ddec;

/* $ Abstract */

/*     Return a 6x6 matrix that transforms states in inertial */
/*     coordinates to states in body-equator-and-prime-meridian */
/*     coordinates. */

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

/*     PCK */
/*     NAIF_IDS */
/*     ROTATION */
/*     TIME */

/* $ Keywords */

/*     TRANSFORMATION */
/*     ROTATION */

/* $ Declarations */
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


/*     Include File:  SPICELIB Error Handling Parameters */

/*        errhnd.inc  Version 2    18-JUN-1997 (WLT) */

/*           The size of the long error message was */
/*           reduced from 25*80 to 23*80 so that it */
/*           will be accepted by the Microsoft Power Station */
/*           FORTRAN compiler which has an upper bound */
/*           of 1900 for the length of a character string. */

/*        errhnd.inc  Version 1    29-JUL-1997 (NJB) */



/*     Maximum length of the long error message: */


/*     Maximum length of the short error message: */


/*     End Include File:  SPICELIB Error Handling Parameters */

/* $ Abstract */

/*     The parameters below form an enumerated list of the recognized */
/*     frame types.  They are: INERTL, PCK, CK, TK, DYN.  The meanings */
/*     are outlined below. */

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

/* $ Parameters */

/*     INERTL      an inertial frame that is listed in the routine */
/*                 CHGIRF and that requires no external file to */
/*                 compute the transformation from or to any other */
/*                 inertial frame. */

/*     PCK         is a frame that is specified relative to some */
/*                 INERTL frame and that has an IAU model that */
/*                 may be retrieved from the PCK system via a call */
/*                 to the routine TISBOD. */

/*     CK          is a frame defined by a C-kernel. */

/*     TK          is a "text kernel" frame.  These frames are offset */
/*                 from their associated "relative" frames by a */
/*                 constant rotation. */

/*     DYN         is a "dynamic" frame.  These currently are */
/*                 parameterized, built-in frames where the full frame */
/*                 definition depends on parameters supplied via a */
/*                 frame kernel. */

/*     ALL         indicates any of the above classes. This parameter */
/*                 is used in APIs that fetch information about frames */
/*                 of a specified class. */


/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     W.L. Taber      (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 4.0.0, 08-MAY-2012 (NJB) */

/*       The parameter ALL was added to support frame fetch APIs. */

/* -    SPICELIB Version 3.0.0, 28-MAY-2004 (NJB) */

/*       The parameter DYN was added to support the dynamic frame class. */

/* -    SPICELIB Version 2.0.0, 12-DEC-1996 (WLT) */

/*        Various unused frames types were removed and the */
/*        frame time TK was added. */

/* -    SPICELIB Version 1.0.0, 10-DEC-1995 (WLT) */

/* -& */

/*     End of INCLUDE file frmtyp.inc */

/* $ Abstract */

/*     This include file defines the dimension of the counter */
/*     array used by various SPICE subsystems to uniquely identify */
/*     changes in their states. */

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

/* $ Parameters */

/*     CTRSIZ      is the dimension of the counter array used by */
/*                 various SPICE subsystems to uniquely identify */
/*                 changes in their states. */

/* $ Author_and_Institution */

/*     B.V. Semenov    (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 29-JUL-2013 (BVS) */

/* -& */

/*     End of include file. */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     REF        I   ID of inertial reference frame to transform from */
/*     BODY       I   ID code of body */
/*     ET         I   Epoch of transformation */
/*     TSIPM      O   Transformation (state), inertial to prime meridian */

/* $ Detailed_Input */

/*     REF         is the NAIF name for an inertial reference frame. */
/*                 Acceptable names include: */

/*                    Name       Description */
/*                    --------   -------------------------------- */
/*                    'J2000'    Earth mean equator, dynamical */
/*                               equinox of J2000 */

/*                    'B1950'    Earth mean equator, dynamical */
/*                               equinox of B1950 */

/*                    'FK4'      Fundamental Catalog (4) */

/*                    'DE-118'   JPL Developmental Ephemeris (118) */

/*                    'DE-96'    JPL Developmental Ephemeris ( 96) */

/*                    'DE-102'   JPL Developmental Ephemeris (102) */

/*                    'DE-108'   JPL Developmental Ephemeris (108) */

/*                    'DE-111'   JPL Developmental Ephemeris (111) */

/*                    'DE-114'   JPL Developmental Ephemeris (114) */

/*                    'DE-122'   JPL Developmental Ephemeris (122) */

/*                    'DE-125'   JPL Developmental Ephemeris (125) */

/*                    'DE-130'   JPL Developmental Ephemeris (130) */

/*                    'GALACTIC' Galactic System II */

/*                    'DE-200'   JPL Developmental Ephemeris (200) */

/*                    'DE-202'   JPL Developmental Ephemeris (202) */

/*                 (See the routine CHGIRF for a full list of names.) */

/*                 The output TIPM will give the transformation */
/*                 from this frame to the bodyfixed frame specified by */
/*                 BODY at the epoch specified by ET. */

/*     BODY        is the integer ID code of the body for which the */
/*                 state transformation matrix is requested. Bodies */
/*                 are numbered according to the standard NAIF */
/*                 numbering scheme. The numbering scheme is */
/*                 explained in the NAIF_IDS required reading file. */

/*     ET          is the epoch at which the state transformation */
/*                 matrix is requested. (This is typically the */
/*                 epoch of observation minus the one-way light time */
/*                 from the observer to the body at the epoch of */
/*                 observation.) */

/* $ Detailed_Output */

/*     TSIPM       is a 6x6 transformation matrix. It is used to */
/*                 transform states from inertial coordinates to body */
/*                 fixed (also called equator and prime meridian --- */
/*                 PM) coordinates. */

/*                 Given a state S in the inertial reference frame */
/*                 specified by REF, the corresponding bodyfixed state */
/*                 is given by the matrix vector product: */

/*                    TSIPM * S */

/*                 The X axis of the PM system is directed  to the */
/*                 intersection of the equator and prime meridian. */
/*                 The Z axis points along  the spin axis and points */
/*                 towards the same side of the invariable plane of */
/*                 the solar system as does earth's north pole. */

/*                 NOTE: The inverse of TSIPM is NOT its transpose. */
/*                       The matrix, TSIPM, has a structure as shown */
/*                       below: */

/*                             -            - */
/*                            |       :      | */
/*                            |   R   :  0   | */
/*                            | ......:......| */
/*                            |       :      | */
/*                            | dR_dt :  R   | */
/*                            |       :      | */
/*                             -            - */

/*                       where R is a time varying rotation matrix and */
/*                       dR_dt is its derivative. The inverse of this */
/*                       matrix is: */

/*                             -              - */
/*                            |     T  :       | */
/*                            |    R   :  0    | */
/*                            | .......:.......| */
/*                            |        :       | */
/*                            |      T :   T   | */
/*                            | dR_dt  :  R    | */
/*                            |        :       | */
/*                             -              - */

/*                       The SPICE routine INVSTM is available for */
/*                       producing this inverse. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If data required to define the body-fixed frame associated */
/*        with BODY are not found in the binary PCK system or the kernel */
/*        pool, the error SPICE(FRAMEDATANOTFOUND) is signaled. In */
/*        the case of IAU style body-fixed frames, the absence of */
/*        prime meridian polynomial data (which are required) is used */
/*        as an indicator of missing data. */

/*     2) If the test for exception (1) passes, but in fact requested */
/*        data are not available in the kernel pool, the error will be */
/*        signaled by routines in the call tree of this routine. */

/*     3) If the kernel pool does not contain all of the data required */
/*        to define the number of nutation precession angles */
/*        corresponding to the available nutation precession */
/*        coefficients, the error SPICE(INSUFFICIENTANGLES) is */
/*        signaled. */

/*     4) If the reference frame REF is not recognized, a routine */
/*        called by TISBOD will diagnose the condition and invoke the */
/*        SPICE error handling system. */

/*     5) If the specified body code BODY is not recognized, the */
/*        error is diagnosed by a routine called by TISBOD. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     The matrix for transforming inertial states to bodyfixed */
/*     states is the 6x6 matrix shown below as a block structured */
/*     matrix. */

/*                 -            - */
/*                |       :      | */
/*                | TIPM  :  0   | */
/*                | ......:......| */
/*                |       :      | */
/*                | DTIPM : TIPM | */
/*                |       :      | */
/*                 -            - */

/*     This can also be expressed in terms of Euler angles */
/*     PHI, DELTA and W. The transformation from inertial to */
/*     bodyfixed coordinates is represented in the SPICE kernel */
/*     pool as: */

/*            TIPM = [W] [DELTA] [PHI] */
/*                      3       1     3 */
/*     Thus */

/*           DTIPM = d[W] /dt [DELTA] [PHI] */
/*                       3           1     3 */

/*                 + [W] d[DELTA] /dt [PHI] */
/*                      3             1     3 */

/*                 + [W] [DELTA] d[PHI] /dt */
/*                      3       1          3 */


/*     If a binary PCK file record can be used for the time and */
/*     body requested, it will be used. The most recently loaded */
/*     binary PCK file has first priority, followed by previously */
/*     loaded binary PCK files in backward time order. If no */
/*     binary PCK file has been loaded, the text P_constants */
/*     kernel file is used. */

/*     If there is only text PCK kernel information, it is */
/*     expressed in terms of RA, DEC and W (same W as above), where */

/*        RA    = PHI - HALFPI() */
/*        DEC   = HALFPI() - DELTA */

/*     The angles RA, DEC, and W are defined as follows in the */
/*     text PCK file: */

/*                                         2      ____ */
/*                                    RA2*t       \ */
/*            RA  = RA0  + RA1*t/T  + ------   +  /     a  sin theta */
/*                                       2        ----   i          i */
/*                                      T           i */

/*                                          2     ____ */
/*                                    DEC2*t      \ */
/*            DEC = DEC0 + DEC1*t/T + -------  +  /    d  cos theta */
/*                                        2       ----  i          i */
/*                                       T          i */


/*                                        2      ____ */
/*                                    W2*t       \ */
/*            W   = W0   + W1*t/d   + -----   +  /     w  sin theta */
/*                                       2       ----   i          i */
/*                                      d          i */


/*     where: */

/*            d = seconds/day */

/*            T = seconds/Julian century */

/*            a , d , and w  arrays apply to satellites only. */
/*             i   i       i */

/*            theta  = THETA0(i) + THETA1(i)*t/T are specific to each */
/*                 i */

/*            planet. */


/*     These angles -- typically nodal rates -- vary in number and */
/*     definition from one planetary system to the next. */

/*     Thus */
/*                                         ____ */
/*                             2*RA2*t     \ */
/*          dRA/dt  = RA1/T  + -------   + /   a THETA1(i)/T cos theta */
/*                                 2       ---- i                     i */
/*                                T          i */

/*                                         ____ */
/*                             2*DEC2*t    \ */
/*          dDEC/dt = DEC1/T + --------  - /    d  THETA1(i)/T sin theta */
/*                                 2       ----  i                      i */
/*                                T          i */

/*                                         ____ */
/*                             2*W2*t      \ */
/*          dW/dt   = W1/d   + ------    + /    w  THETA1(i)/T cos theta */
/*                                 2       ----  i                      i */
/*                                d          i */


/* $ Examples */

/*     Note that the data needed to compute the output state transition */
/*     matrix must have been made available to your program by having */
/*     loaded an appropriate binary or text PCK file via FURNSH. */

/*     Example 1. */

/*     In the following code fragment, TISBOD is used to transform */
/*     a state in J2000 inertial coordinates to a state in bodyfixed */
/*     coordinates. */

/*     The 6-vectors EULANG represents the inertial state (position and */
/*     velocity) of an object with respect to the center of the body */
/*     at time ET. */

/*     C */
/*     C     First load the kernel pool. */
/*     C */
/*           CALL FURNSH ( 'PLANETARY_CONSTANTS.KER' ) */

/*     C */
/*     C     Next get the transformation and its derivative. */
/*     C */
/*           CALL TISBOD ( 'J2000', BODY, ET, TSIPM ) */

/*     C */
/*     C     Convert position to bodyfixed coordinates. */
/*     C */
/*           CALL MXVG    ( TSIPM, EULANG, 6, 6, BDSTAT ) */


/*     Example 2. */

/*     In the example below, TISBOD is used to compute */
/*     the angular velocity vector (with respect to an inertial frame) */
/*     of the specified body at time ET. */

/*     C */
/*     C     First get the state transformation matrix. */
/*     C */
/*           CALL TISBOD ( BODY,  ET,   TSIPM ) */

/*     C */
/*     C     This matrix has the form: */
/*     C */
/*     C           -            - */
/*     C          |       :      | */
/*     C          | TIPM  :  0   | */
/*     C          | ......:......| */
/*     C          |       :      | */
/*     C          | DTIPM : TIPM | */
/*     C          |       :      | */
/*     C           -            - */
/*     C */
/*     C     We extract TIPM and DTIPM */
/*     C */

/*           DO  I = 1,3 */
/*              DO  J = 1,3 */

/*                 TIPM  ( I, J ) = TSIPM ( I,   J ) */
/*                 DTIPM ( I, J ) = TSIPM ( I+3, J ) */

/*              END DO */
/*           END DO */

/*     C */
/*     C     The transpose of TIPM and DTIPM, (TPMI and DTPMI), give */
/*     C     the transformation from bodyfixed coordinates to inertial */
/*     C     coordinates. */
/*     C */
/*     C     Here is a fact about the relationship between angular */
/*     C     velocity associated with a time varying rotation matrix */
/*     C     that gives the orientation of a body with respect to */
/*     C     an inertial frame. */
/*     C */
/*     C        The angular velocity vector can be read from the off */
/*     C        diagonal components of the matrix product: */
/*     C */
/*     C                                t */
/*     C        OMEGA =     DTPMI * TPMI */
/*     C */
/*     C                         t */
/*     C              =     DTIPM * TIPM */
/*     C */
/*     C        the components of the angular velocity V will appear */
/*     C        in this matrix as: */
/*     C */
/*     C             _                   _ */
/*     C            |                     | */
/*     C            |   0    -V(3)  V(2)  | */
/*     C            |                     | */
/*     C            |  V(3)    0   -V(1)  | */
/*     C            |                     | */
/*     C            | -V(2)   V(1)   0    | */
/*     C            |_                   _| */
/*     C */
/*     C */
/*           CALL MTXM ( DTIPM, TIPM, OMEGA ) */

/*           V(1) = OMEGA (3,2) */
/*           V(2) = OMEGA (1,3) */
/*           V(3) = OMEGA (2,1) */

/* $ Restrictions */

/*     The kernel pool must be loaded with the appropriate coefficients */
/*     (from the P_constants kernel or binary PCK file) prior to */
/*     calling this routine. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N. J. Bachman   (JPL) */
/*     B. V. Semenov   (JPL) */
/*     W. L. Taber     (JPL) */
/*     K. S. Zukor     (JPL) */

/* $ Version */

/* -    SPICELIB Version 4.5.0, 26-JUL-2016 (BVS) */

/*        The routine was updated to be more efficient by using a hash */
/*        and buffers so save text PCK data instead of doing kernel POOL */
/*        look-ups over an over again. The routine now checks the POOL */
/*        state counter and dumps all buffered data if it changes. */

/*        BUG FIX: changed available room in the BODVCD call */
/*        fetching 'NUT_PREC_ANGLES' from MAXANG to MAXANG*2. */

/* -    SPICELIB Version 4.4.0, 01-FEB-2008 (NJB) */

/*        The routine was updated to improve the error messages created */
/*        when required PCK data are not found. Now in most cases the */
/*        messages are created locally rather than by the kernel pool */
/*        access routines. In particular missing binary PCK data will */
/*        be indicated with a reasonable error message. */

/* -    SPICELIB Version 4.3.0, 13-DEC-2005 (NJB) */

/*        Bug fix:  previous update introduced bug in state */
/*        transformation when REF was unequal to PCK native frame. */

/* -    SPICELIB Version 4.2.0, 23-OCT-2005 (NJB) */

/*        Re-wrote portions of algorithm to simplify source code. */
/*        Updated to remove non-standard use of duplicate arguments */
/*        in MXM and VADDG calls. */

/*        Replaced calls to ZZBODVCD with calls to BODVCD. */

/* -    SPICELIB Version 4.1.0, 05-JAN-2005 (NJB) */

/*        Tests of routine FAILED() were added. */

/* -     SPICELIB Version 4.0.0, 12-FEB-2004 (NJB) */

/*         Code has been updated to support satellite ID codes in the */
/*         range 10000 to 99999 and to allow nutation precession angles */
/*         to be associated with any object. */

/*         Implementation changes were made to improve robustness */
/*         of the code. */

/* -     SPICELIB Version 3.3.0, 29-MAR-1995 (WLT) */

/*         Properly initialized the variable NPAIRS. */

/* -     SPICELIB Version 3.2.0, 22-MAR-1995 (KSZ) */

/*         Changed to call PCKMAT rather than PCKEUL. */

/* -     SPICELIB Version 3.1.0, 18-OCT-1994 (KSZ) */

/*         Fixed bug which incorrectly modded DW by two pi. */

/* -     SPICELIB Version 3.0.0, 10-MAR-1994 (KSZ) */

/*         Changed to look for binary PCK file, and used this */
/*         to find Euler angles, if such data has been loaded. */

/* -     SPICELIB Version 2.0.1, 10-MAR-1992 (WLT) */

/*         Comment section for permuted index source lines was added */
/*         following the header. */

/* -     SPICELIB Version 2.0.0, 04-SEP-1991 (NJB) */

/*         Updated to handle P_constants referenced to different epochs */
/*         and inertial reference frames. */

/*         $Required_Reading and $Literature_References sections were */
/*         updated. */

/* -     SPICELIB Version 1.0.0, 05-NOV-1990 (WLT) */

/* -& */
/* $ Index_Entries */

/*     transformation from inertial state to bodyfixed */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 4.5.0, 02-MAR-2016 (BVS) */

/*        The routine was updated to be more efficient by using a hash */
/*        and buffers so save text PCK data instead of doing kernel POOL */
/*        look-ups over an over again. The routine now checks the POOL */
/*        state counter and dumps all buffered data if it changes. */

/* -    SPICELIB Version 4.2.0, 06-SEP-2005 (NJB) */

/*        Re-wrote portions of algorithm to simplify source code. */
/*        The routine now takes advantage of EUL2XF, which wasn't */
/*        available when the first version of this routine was written. */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in MXM and VADDG calls. */

/*        Replaced calls to ZZBODVCD with calls to BODVCD. */

/* -    SPICELIB Version 1.1.0, 05-JAN-2005 (NJB) */

/*        Tests of routine FAILED() were added. The new checks */
/*        are intended to prevent arithmetic operations from */
/*        being performed with uninitialized or invalid data. */

/* -     SPICELIB Version 4.0.0, 27-JAN-2004 (NJB) */

/*         Code has been updated to support satellite ID codes in the */
/*         range 10000 to 99999 and to allow nutation precession angles */
/*         to be associated with any object. */

/*         Calls to deprecated kernel pool access routine RTPOOL */
/*         were replaced by calls to GDPOOL. */

/*         Calls to BODVAR have been replaced with calls to */
/*         ZZBODVCD. */

/* -     SPICELIB Version 3.3.0, 29-MAR-1995 (WLT) */

/*        The variable NPAIRS is now initialized */
/*        at the same point as NA, NTHETA, ND, and NW to be */
/*        zero. This prevents the routine from performing */
/*        needless calculations for planets and avoids possible */
/*        floating point exceptions. */

/* -     SPICELIB Version 3.2.0, 22-MAR-1995 (KSZ) */

/*        TISBOD now gets the TSIPM matrix from PCKMAT. */
/*        Reference frame calculation moved to end. */

/* -     SPICELIB Version 3.0.1, 07-OCT-1994 (KSZ) */

/*        TISBOD bug which mistakenly moded DW by 2PI */
/*        was removed. */

/* -     SPICELIB Version 3.0.0, 10-MAR-1994 (KSZ) */

/*        TISBOD now uses new software to check for the */
/*        existence of binary PCK files, search the for */
/*        data corresponding to the requested body and time, */
/*        and return the appropriate Euler angles. Otherwise */
/*        the code calculates the Euler angles from the */
/*        P_constants kernel file. */

/* -     SPICELIB Version 2.0.0, 04-SEP-1991 (NJB) */

/*         Updated to handle P_constants referenced to different epochs */
/*         and inertial reference frames. */

/*         TISBOD now checks the kernel pool for presence of the */
/*         variables */

/*            BODY#_CONSTANTS_REF_FRAME */

/*         and */

/*            BODY#_CONSTANTS_JED_EPOCH */

/*         where # is the NAIF integer code of the barycenter of a */
/*         planetary system or of a body other than a planet or */
/*         satellite. If either or both of these variables are */
/*         present, the P_constants for BODY are presumed to be */
/*         referenced to the specified inertial frame or epoch. */
/*         If the epoch of the constants is not J2000, the input */
/*         time ET is converted to seconds past the reference epoch. */
/*         If the frame of the constants is not the frame specified */
/*         by REF, the rotation from the P_constants' frame to */
/*         body-fixed coordinates is transformed to the rotation from */
/*         the requested frame to body-fixed coordinates. The same */
/*         transformation is applied to the derivative of this */
/*         rotation. */

/*         Due to the prescience of the original author, the code */
/*         was already prepared to handle the possibility of */
/*         specification of a P_constants inertial reference frame via */
/*         kernel pool variables. */


/*         Also, the $Required_Reading and $Literature_References */
/*         sections were updated. The SPK required reading has been */
/*         deleted from the $Literature_References section, and the */
/*         NAIF_IDS, KERNEL, and TIME Required Reading files have */
/*         been added in the $Required_Reading section. */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */


/*     POOL state counter. */


/*     ID-based hash for text PCK data. KIDLST, KIDPOL, and KIDIDS */
/*     provide the index in the body PCK data arrays at which the data */
/*     of the body with a given ID are stored. */


/*     Saved variables */

/*     Because we need to save almost everything, we save everything */
/*     rather than taking a chance and accidentally leaving something */
/*     off the list. */


/*     Initial values */


/*     Standard SPICE error handling. */

    if (return_()) {
	return 0;
    } else {
	chkin_("TISBOD", (ftnlen)6);
    }

/*     Perform any needed first pass initializations. */

    if (first) {

/*        Initialize POOL state counter to the user value. */

	zzctruin_(pulctr);

/*        Initialize kernel POOL frame hashes. */

	zzhsiini_(&c__157, bidlst, bidpol);

/*        Get the code for the J2000 frame. */

	irfnum_("J2000", &j2code, (ftnlen)5);

/*        Set seconds per day and per century. */

	d__ = spd_();
	t = d__ * 36525.;
	first = FALSE_;
    }
    irfnum_(ref, &reqref, ref_len);

/*     Get state transformation matrix from high precision PCK file, if */
/*     available. */

    pckmat_(body, et, &pcref, tsipm, &found);
    if (! found) {

/*        The data for the frame of interest are not available in a */
/*        loaded binary PCK file. This is not an error: the data may be */
/*        present in the kernel pool. */

/*        Check the POOL counter. If it changed, dump all buffered */
/*        constants data. */

	zzpctrck_(pulctr, &update);
	if (update) {
	    zzhsiini_(&c__157, bidlst, bidpol);
	}

/*        Check if we have data for this body in our buffers. */

	zzhsichk_(bidlst, bidpol, bidids, body, &at);
	if (at != 0) {

/*           Set PCREF as it is used after the text PCK "IF". */

	    pcref = bpcref[(i__1 = at - 1) < 157 && 0 <= i__1 ? i__1 : s_rnge(
		    "bpcref", i__1, "tisbod_", (ftnlen)867)];
	} else {

/*           Conduct a non-error-signaling check for the presence of a */
/*           kernel variable that is required to implement an IAU style */
/*           body-fixed reference frame. If the data aren't available, */
/*           we don't want BODVCD to signal a SPICE(KERNELVARNOTFOUND) */
/*           error; we want to issue the error signal locally, with a */
/*           better error message. */

	    s_copy(item, "BODY#_PM", (ftnlen)32, (ftnlen)8);
	    repmi_(item, "#", body, item, (ftnlen)32, (ftnlen)1, (ftnlen)32);
	    dtpool_(item, &found, &nw, dtype, (ftnlen)32, (ftnlen)1);
	    if (! found) {

/*              Now we do have an error. */

/*              We don't have the data we'll need to produced the */
/*              requested state transformation matrix. In order to */
/*              create an error message understandable to the user, */
/*              find, if possible, the name of the reference frame */
/*              associated with the input body. Note that the body is */
/*              really identified by a PCK frame class ID code, though */
/*              most of the documentation just calls it a body ID code. */

		ccifrm_(&c__2, body, &frcode, fixfrm, &cent, &found, (ftnlen)
			32);
		etcal_(et, timstr, (ftnlen)35);
		s_copy(errmsg, "PCK data required to compute the orientation"
			" of the # # for epoch # TDB were not found. If these"
			" data were to be provided by a binary PCK file, then"
			" it is possible that the PCK file does not have cove"
			"rage for the specified body-fixed frame at the time "
			"of interest. If the data were to be provided by a te"
			"xt PCK file, then possibly the file does not contain"
			" data for the specified body-fixed frame. In either "
			"case it is possible that a required PCK file was not"
			" loaded at all.", (ftnlen)1840, (ftnlen)475);

/*              Fill in the variable data in the error message. */

		if (found) {

/*                 The frame system knows the name of the body-fixed */
/*                 frame. */

		    setmsg_(errmsg, (ftnlen)1840);
		    errch_("#", "body-fixed frame", (ftnlen)1, (ftnlen)16);
		    errch_("#", fixfrm, (ftnlen)1, (ftnlen)32);
		    errch_("#", timstr, (ftnlen)1, (ftnlen)35);
		} else {

/*                 The frame system doesn't know the name of the */
/*                 body-fixed frame, most likely due to a missing */
/*                 frame kernel. */

		    suffix_("#", &c__1, errmsg, (ftnlen)1, (ftnlen)1840);
		    setmsg_(errmsg, (ftnlen)1840);
		    errch_("#", "body-fixed frame associated with the ID code"
			    , (ftnlen)1, (ftnlen)44);
		    errint_("#", body, (ftnlen)1);
		    errch_("#", timstr, (ftnlen)1, (ftnlen)35);
		    errch_("#", "Also, a frame kernel defining the body-fixe"
			    "d frame associated with body # may need to be lo"
			    "aded.", (ftnlen)1, (ftnlen)96);
		    errint_("#", body, (ftnlen)1);
		}
		sigerr_("SPICE(FRAMEDATANOTFOUND)", (ftnlen)24);
		chkout_("TISBOD", (ftnlen)6);
		return 0;
	    }

/*           Find the body code used to label the reference frame and */
/*           epoch specifiers for the orientation constants for BODY. */

/*           For planetary systems, the reference frame and epoch for */
/*           the orientation constants is associated with the system */
/*           barycenter, not with individual bodies in the system. For */
/*           any other bodies, (the Sun or asteroids, for example) the */
/*           body's own code is used as the label. */

	    refid = zzbodbry_(body);

/*           Look up the epoch of the constants. The epoch is specified */
/*           as a Julian ephemeris date. The epoch defaults to J2000. */

	    s_copy(item, "BODY#_CONSTANTS_JED_EPOCH", (ftnlen)32, (ftnlen)25);
	    repmi_(item, "#", &refid, item, (ftnlen)32, (ftnlen)1, (ftnlen)32)
		    ;
	    gdpool_(item, &c__1, &c__1, &dim, &pckepc, &found, (ftnlen)32);
	    if (! found) {
		pckepc = j2000_();
	    }

/*           Look up the reference frame of the constants. The reference */
/*           frame is specified by a code recognized by CHGIRF. The */
/*           default frame is J2000, symbolized by the code J2CODE. */

	    s_copy(item, "BODY#_CONSTANTS_REF_FRAME", (ftnlen)32, (ftnlen)25);
	    repmi_(item, "#", &refid, item, (ftnlen)32, (ftnlen)1, (ftnlen)32)
		    ;
	    gdpool_(item, &c__1, &c__1, &dim, &pckref, &found, (ftnlen)32);
	    if (found) {
		pcref = i_dnnt(&pckref);
	    } else {
		pcref = j2code;
	    }

/*           Whatever the body, it has quadratic time polynomials for */
/*           the RA and Dec of the pole, and for the rotation of the */
/*           Prime Meridian. */

	    s_copy(item, "POLE_RA", (ftnlen)32, (ftnlen)7);
	    cleard_(&c__3, rcoef);
	    bodvcd_(body, item, &c__3, &na, rcoef, (ftnlen)32);
	    if (failed_()) {
		chkout_("TISBOD", (ftnlen)6);
		return 0;
	    }
	    s_copy(item, "POLE_DEC", (ftnlen)32, (ftnlen)8);
	    cleard_(&c__3, dcoef);
	    bodvcd_(body, item, &c__3, &nd, dcoef, (ftnlen)32);
	    if (failed_()) {
		chkout_("TISBOD", (ftnlen)6);
		return 0;
	    }
	    s_copy(item, "PM", (ftnlen)32, (ftnlen)2);
	    cleard_(&c__3, wcoef);
	    bodvcd_(body, item, &c__3, &nw, wcoef, (ftnlen)32);
	    if (failed_()) {
		chkout_("TISBOD", (ftnlen)6);
		return 0;
	    }

/*           If the body is a satellite, there may be additional */
/*           nutation and libration (THETA) terms. */

	    ntheta = 0;
	    npairs = 0;
	    na = 0;
	    nd = 0;
	    nw = 0;
	    s_copy(item, "NUT_PREC_ANGLES", (ftnlen)32, (ftnlen)15);

/*           There is something a bit obscure going on below. We are */
/*           passing a two dimensional array ( TCOEF(2, MAXANG) ). But */
/*           BODVCD is expecting a 1- dimensional array. BODVCD loads */
/*           the array TCOEF in the following order */

/*              TCOEF(1,1), TCOEF(2,1), TCOEF(1,2), TCOEF(2,2),   ... */

/*           The NTHETA that comes back is the total number of items */
/*           loaded, but we will need the actual limit on the second */
/*           dimension. That is --- NTHETA / 2. */

	    if (bodfnd_(&refid, item, (ftnlen)32)) {
		bodvcd_(&refid, item, &c__200, &ntheta, tcoef, (ftnlen)32);
		if (failed_()) {
		    chkout_("TISBOD", (ftnlen)6);
		    return 0;
		}
		npairs = ntheta / 2;
	    }

/*           Look up the right ascension nutations in the precession of */
/*           the pole. NA is the number of Ascension coefficients. AC */
/*           are the Ascension coefficients. */

	    s_copy(item, "NUT_PREC_RA", (ftnlen)32, (ftnlen)11);
	    if (bodfnd_(body, item, (ftnlen)32)) {
		bodvcd_(body, item, &c__100, &na, ac, (ftnlen)32);
		if (failed_()) {
		    chkout_("TISBOD", (ftnlen)6);
		    return 0;
		}
	    }

/*           Look up the declination nutations in the precession of the */
/*           pole. ND is the number of Declination coefficients. DC are */
/*           the Declination coefficients. */

	    s_copy(item, "NUT_PREC_DEC", (ftnlen)32, (ftnlen)12);
	    if (bodfnd_(body, item, (ftnlen)32)) {
		bodvcd_(body, item, &c__100, &nd, dc, (ftnlen)32);
		if (failed_()) {
		    chkout_("TISBOD", (ftnlen)6);
		    return 0;
		}
	    }

/*           Finally look up the prime meridian nutations. NW is the */
/*           number of coefficients. WC is the array of coefficients. */

	    s_copy(item, "NUT_PREC_PM", (ftnlen)32, (ftnlen)11);
	    if (bodfnd_(body, item, (ftnlen)32)) {
		bodvcd_(body, item, &c__100, &nw, wc, (ftnlen)32);
		if (failed_()) {
		    chkout_("TISBOD", (ftnlen)6);
		    return 0;
		}
	    }

/*           The number of coefficients returned had better not be */
/*           bigger than the number of angles we are going to compute. */
/*           If it is we simply signal an error and bag it, for sure. */

/* Computing MAX */
	    i__1 = max(na,nd);
	    if (max(i__1,nw) > npairs) {
		setmsg_("Insufficient number of nutation/precession angles f"
			"or body * at time #.", (ftnlen)71);
		errint_("*", body, (ftnlen)1);
		errdp_("#", et, (ftnlen)1);
		sigerr_("SPICE(INSUFFICIENTANGLES)", (ftnlen)25);
		chkout_("TISBOD", (ftnlen)6);
		return 0;
	    }

/*           We succeeded to fetch all data for this body. Save it in */
/*           the buffers. First check if there is room. If not, dump the */
/*           buffers to make room. */

	    zzhsiavl_(bidpol, &avail);
	    if (avail <= 0) {
		zzhsiini_(&c__157, bidlst, bidpol);
	    }

/*           Add this body to the hash and save its data in the buffers. */

	    zzhsiadd_(bidlst, bidpol, bidids, body, &at, &new__);
	    bpckep[(i__1 = at - 1) < 157 && 0 <= i__1 ? i__1 : s_rnge("bpckep"
		    , i__1, "tisbod_", (ftnlen)1147)] = pckepc;
	    bpcref[(i__1 = at - 1) < 157 && 0 <= i__1 ? i__1 : s_rnge("bpcref"
		    , i__1, "tisbod_", (ftnlen)1148)] = pcref;
	    bnpair[(i__1 = at - 1) < 157 && 0 <= i__1 ? i__1 : s_rnge("bnpair"
		    , i__1, "tisbod_", (ftnlen)1149)] = npairs;
	    bna[(i__1 = at - 1) < 157 && 0 <= i__1 ? i__1 : s_rnge("bna", 
		    i__1, "tisbod_", (ftnlen)1150)] = na;
	    bnd[(i__1 = at - 1) < 157 && 0 <= i__1 ? i__1 : s_rnge("bnd", 
		    i__1, "tisbod_", (ftnlen)1151)] = nd;
	    bnw[(i__1 = at - 1) < 157 && 0 <= i__1 ? i__1 : s_rnge("bnw", 
		    i__1, "tisbod_", (ftnlen)1152)] = nw;
	    moved_(rcoef, &c__3, &brcoef[(i__1 = at * 3 - 3) < 471 && 0 <= 
		    i__1 ? i__1 : s_rnge("brcoef", i__1, "tisbod_", (ftnlen)
		    1154)]);
	    moved_(dcoef, &c__3, &bdcoef[(i__1 = at * 3 - 3) < 471 && 0 <= 
		    i__1 ? i__1 : s_rnge("bdcoef", i__1, "tisbod_", (ftnlen)
		    1155)]);
	    moved_(wcoef, &c__3, &bwcoef[(i__1 = at * 3 - 3) < 471 && 0 <= 
		    i__1 ? i__1 : s_rnge("bwcoef", i__1, "tisbod_", (ftnlen)
		    1156)]);
	    moved_(tcoef, &c__200, &btcoef[(i__1 = (at * 100 + 1 << 1) - 202) 
		    < 31400 && 0 <= i__1 ? i__1 : s_rnge("btcoef", i__1, 
		    "tisbod_", (ftnlen)1157)]);
	    moved_(ac, &c__100, &bac[(i__1 = at * 100 - 100) < 15700 && 0 <= 
		    i__1 ? i__1 : s_rnge("bac", i__1, "tisbod_", (ftnlen)1158)
		    ]);
	    moved_(dc, &c__100, &bdc[(i__1 = at * 100 - 100) < 15700 && 0 <= 
		    i__1 ? i__1 : s_rnge("bdc", i__1, "tisbod_", (ftnlen)1159)
		    ]);
	    moved_(wc, &c__100, &bwc[(i__1 = at * 100 - 100) < 15700 && 0 <= 
		    i__1 ? i__1 : s_rnge("bwc", i__1, "tisbod_", (ftnlen)1160)
		    ]);
	}

/*        The reference epoch in the PCK is given as JED. Convert to */
/*        ephemeris seconds past J2000. Then convert the input ET to */
/*        seconds past the reference epoch. */

	tmpepc = spd_() * (bpckep[(i__1 = at - 1) < 157 && 0 <= i__1 ? i__1 : 
		s_rnge("bpckep", i__1, "tisbod_", (ftnlen)1169)] - j2000_());
	epoch = *et - tmpepc;

/*        Evaluate the time polynomials and their derivatives w.r.t. */
/*        EPOCH at EPOCH. */

/*        Evaluate the time polynomials at EPOCH. */

	ra = brcoef[(i__1 = at * 3 - 3) < 471 && 0 <= i__1 ? i__1 : s_rnge(
		"brcoef", i__1, "tisbod_", (ftnlen)1178)] + epoch / t * (
		brcoef[(i__2 = at * 3 - 2) < 471 && 0 <= i__2 ? i__2 : s_rnge(
		"brcoef", i__2, "tisbod_", (ftnlen)1178)] + epoch / t * 
		brcoef[(i__3 = at * 3 - 1) < 471 && 0 <= i__3 ? i__3 : s_rnge(
		"brcoef", i__3, "tisbod_", (ftnlen)1178)]);
	dec = bdcoef[(i__1 = at * 3 - 3) < 471 && 0 <= i__1 ? i__1 : s_rnge(
		"bdcoef", i__1, "tisbod_", (ftnlen)1180)] + epoch / t * (
		bdcoef[(i__2 = at * 3 - 2) < 471 && 0 <= i__2 ? i__2 : s_rnge(
		"bdcoef", i__2, "tisbod_", (ftnlen)1180)] + epoch / t * 
		bdcoef[(i__3 = at * 3 - 1) < 471 && 0 <= i__3 ? i__3 : s_rnge(
		"bdcoef", i__3, "tisbod_", (ftnlen)1180)]);
	w = bwcoef[(i__1 = at * 3 - 3) < 471 && 0 <= i__1 ? i__1 : s_rnge(
		"bwcoef", i__1, "tisbod_", (ftnlen)1182)] + epoch / d__ * (
		bwcoef[(i__2 = at * 3 - 2) < 471 && 0 <= i__2 ? i__2 : s_rnge(
		"bwcoef", i__2, "tisbod_", (ftnlen)1182)] + epoch / d__ * 
		bwcoef[(i__3 = at * 3 - 1) < 471 && 0 <= i__3 ? i__3 : s_rnge(
		"bwcoef", i__3, "tisbod_", (ftnlen)1182)]);
	dra = (brcoef[(i__1 = at * 3 - 2) < 471 && 0 <= i__1 ? i__1 : s_rnge(
		"brcoef", i__1, "tisbod_", (ftnlen)1185)] + epoch / t * 2. * 
		brcoef[(i__2 = at * 3 - 1) < 471 && 0 <= i__2 ? i__2 : s_rnge(
		"brcoef", i__2, "tisbod_", (ftnlen)1185)]) / t;
	ddec = (bdcoef[(i__1 = at * 3 - 2) < 471 && 0 <= i__1 ? i__1 : s_rnge(
		"bdcoef", i__1, "tisbod_", (ftnlen)1186)] + epoch / t * 2. * 
		bdcoef[(i__2 = at * 3 - 1) < 471 && 0 <= i__2 ? i__2 : s_rnge(
		"bdcoef", i__2, "tisbod_", (ftnlen)1186)]) / t;
	dw = (bwcoef[(i__1 = at * 3 - 2) < 471 && 0 <= i__1 ? i__1 : s_rnge(
		"bwcoef", i__1, "tisbod_", (ftnlen)1187)] + epoch / d__ * 2. *
		 bwcoef[(i__2 = at * 3 - 1) < 471 && 0 <= i__2 ? i__2 : 
		s_rnge("bwcoef", i__2, "tisbod_", (ftnlen)1187)]) / d__;

/*        Compute the nutations and librations (and their derivatives) */
/*        as appropriate. */

	i__2 = bnpair[(i__1 = at - 1) < 157 && 0 <= i__1 ? i__1 : s_rnge(
		"bnpair", i__1, "tisbod_", (ftnlen)1194)];
	for (i__ = 1; i__ <= i__2; ++i__) {
	    theta = (btcoef[(i__1 = (i__ + at * 100 << 1) - 202) < 31400 && 0 
		    <= i__1 ? i__1 : s_rnge("btcoef", i__1, "tisbod_", (
		    ftnlen)1196)] + epoch / t * btcoef[(i__3 = (i__ + at * 
		    100 << 1) - 201) < 31400 && 0 <= i__3 ? i__3 : s_rnge(
		    "btcoef", i__3, "tisbod_", (ftnlen)1196)]) * rpd_();
	    dtheta = btcoef[(i__1 = (i__ + at * 100 << 1) - 201) < 31400 && 0 
		    <= i__1 ? i__1 : s_rnge("btcoef", i__1, "tisbod_", (
		    ftnlen)1198)] / t * rpd_();
	    sintmp = sin(theta);
	    costmp = cos(theta);
	    sinth[(i__1 = i__ - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("sinth",
		     i__1, "tisbod_", (ftnlen)1203)] = sintmp;
	    costh[(i__1 = i__ - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("costh",
		     i__1, "tisbod_", (ftnlen)1204)] = costmp;
	    dsinth[(i__1 = i__ - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("dsin"
		    "th", i__1, "tisbod_", (ftnlen)1205)] = costmp * dtheta;
	    dcosth[(i__1 = i__ - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("dcos"
		    "th", i__1, "tisbod_", (ftnlen)1206)] = -sintmp * dtheta;
	}

/*        Adjust RA, DEC, W and their derivatives by the librations */
/*        and nutations. */

	ra += vdotg_(&bac[(i__2 = at * 100 - 100) < 15700 && 0 <= i__2 ? i__2 
		: s_rnge("bac", i__2, "tisbod_", (ftnlen)1214)], sinth, &bna[(
		i__1 = at - 1) < 157 && 0 <= i__1 ? i__1 : s_rnge("bna", i__1,
		 "tisbod_", (ftnlen)1214)]);
	dec += vdotg_(&bdc[(i__2 = at * 100 - 100) < 15700 && 0 <= i__2 ? 
		i__2 : s_rnge("bdc", i__2, "tisbod_", (ftnlen)1215)], costh, &
		bnd[(i__1 = at - 1) < 157 && 0 <= i__1 ? i__1 : s_rnge("bnd", 
		i__1, "tisbod_", (ftnlen)1215)]);
	w += vdotg_(&bwc[(i__2 = at * 100 - 100) < 15700 && 0 <= i__2 ? i__2 :
		 s_rnge("bwc", i__2, "tisbod_", (ftnlen)1216)], sinth, &bnw[(
		i__1 = at - 1) < 157 && 0 <= i__1 ? i__1 : s_rnge("bnw", i__1,
		 "tisbod_", (ftnlen)1216)]);
	dra += vdotg_(&bac[(i__2 = at * 100 - 100) < 15700 && 0 <= i__2 ? 
		i__2 : s_rnge("bac", i__2, "tisbod_", (ftnlen)1218)], dsinth, 
		&bna[(i__1 = at - 1) < 157 && 0 <= i__1 ? i__1 : s_rnge("bna",
		 i__1, "tisbod_", (ftnlen)1218)]);
	ddec += vdotg_(&bdc[(i__2 = at * 100 - 100) < 15700 && 0 <= i__2 ? 
		i__2 : s_rnge("bdc", i__2, "tisbod_", (ftnlen)1219)], dcosth, 
		&bnd[(i__1 = at - 1) < 157 && 0 <= i__1 ? i__1 : s_rnge("bnd",
		 i__1, "tisbod_", (ftnlen)1219)]);
	dw += vdotg_(&bwc[(i__2 = at * 100 - 100) < 15700 && 0 <= i__2 ? i__2 
		: s_rnge("bwc", i__2, "tisbod_", (ftnlen)1220)], dsinth, &bnw[
		(i__1 = at - 1) < 157 && 0 <= i__1 ? i__1 : s_rnge("bnw", 
		i__1, "tisbod_", (ftnlen)1220)]);

/*        Convert from degrees to radians */

	ra *= rpd_();
	dec *= rpd_();
	w *= rpd_();
	dra *= rpd_();
	ddec *= rpd_();
	dw *= rpd_();

/*        Convert to Euler angles. */

	d__1 = twopi_();
	w = d_mod(&w, &d__1);
	phi = ra + halfpi_();
	delta = halfpi_() - dec;
	dphi = dra;
	ddelta = -ddec;
	if (failed_()) {
	    chkout_("TISBOD", (ftnlen)6);
	    return 0;
	}

/*        Pack the Euler angles and their derivatives into */
/*        a state vector. */

	vpack_(&w, &delta, &phi, eulsta);
	vpack_(&dw, &ddelta, &dphi, &eulsta[3]);

/*        Find the state transformation defined by the Euler angle */
/*        state vector. The transformation matrix TSIPM has the */
/*        following structure: */

/*            -            - */
/*           |       :      | */
/*           | TIPM  :  0   | */
/*           | ......:......| */
/*           |       :      | */
/*           | DTIPM : TIPM | */
/*           |       :      | */
/*            -            - */

	eul2xf_(eulsta, &c__3, &c__1, &c__3, tsipm);
    }

/*     At this point the base frame PCREF has been determined. */

/*     If the requested base frame is not base frame associated with the */
/*     PCK data, adjust the transformation matrix TSIPM to map from the */
/*     requested frame to the body-fixed frame. */

    if (reqref != pcref) {

/*        Next get the position transformation from the user specified */
/*        inertial frame to the native PCK inertial frame. */

	irfrot_(&reqref, &pcref, req2pc);
	if (failed_()) {
	    chkout_("TISBOD", (ftnlen)6);
	    return 0;
	}

/*        Since we're applying an inertial transformation to TSIPM, */
/*        we can rotate the non-zero blocks of TSIPM. This saves */
/*        a bunch of double precision multiplications. */

/*        Extract the upper and lower left blocks of TSIPM. */

	for (i__ = 1; i__ <= 3; ++i__) {
	    for (j = 1; j <= 3; ++j) {
		tipm[(i__2 = i__ + j * 3 - 4) < 9 && 0 <= i__2 ? i__2 : 
			s_rnge("tipm", i__2, "tisbod_", (ftnlen)1304)] = 
			tsipm[(i__1 = i__ + j * 6 - 7) < 36 && 0 <= i__1 ? 
			i__1 : s_rnge("tsipm", i__1, "tisbod_", (ftnlen)1304)]
			;
		dtipm[(i__2 = i__ + j * 3 - 4) < 9 && 0 <= i__2 ? i__2 : 
			s_rnge("dtipm", i__2, "tisbod_", (ftnlen)1305)] = 
			tsipm[(i__1 = i__ + 3 + j * 6 - 7) < 36 && 0 <= i__1 ?
			 i__1 : s_rnge("tsipm", i__1, "tisbod_", (ftnlen)1305)
			];
	    }
	}

/*        Rotate the blocks. Note this is a right multiplication. */

	mxm_(tipm, req2pc, xtipm);
	mxm_(dtipm, req2pc, xdtipm);

/*        Replace the non-zero blocks of TSIPM. This gives us the */
/*        transformation from the requested frame to the */
/*        bodyfixed frame. */

	for (i__ = 1; i__ <= 3; ++i__) {
	    for (j = 1; j <= 3; ++j) {
		tsipm[(i__2 = i__ + j * 6 - 7) < 36 && 0 <= i__2 ? i__2 : 
			s_rnge("tsipm", i__2, "tisbod_", (ftnlen)1326)] = 
			xtipm[(i__1 = i__ + j * 3 - 4) < 9 && 0 <= i__1 ? 
			i__1 : s_rnge("xtipm", i__1, "tisbod_", (ftnlen)1326)]
			;
		tsipm[(i__2 = i__ + 3 + (j + 3) * 6 - 7) < 36 && 0 <= i__2 ? 
			i__2 : s_rnge("tsipm", i__2, "tisbod_", (ftnlen)1327)]
			 = xtipm[(i__1 = i__ + j * 3 - 4) < 9 && 0 <= i__1 ? 
			i__1 : s_rnge("xtipm", i__1, "tisbod_", (ftnlen)1327)]
			;
		tsipm[(i__2 = i__ + 3 + j * 6 - 7) < 36 && 0 <= i__2 ? i__2 : 
			s_rnge("tsipm", i__2, "tisbod_", (ftnlen)1328)] = 
			xdtipm[(i__1 = i__ + j * 3 - 4) < 9 && 0 <= i__1 ? 
			i__1 : s_rnge("xdtipm", i__1, "tisbod_", (ftnlen)1328)
			];
	    }
	}
    }

/*     That's all folks. Check out and get out. */

    chkout_("TISBOD", (ftnlen)6);
    return 0;
} /* tisbod_ */

