libmkdsk = static_library(
    'mkdsk', [
        'prscml.c',
        'addcom.c',
        'extmsi.c',
        'rdgrd5.c',
        'makvtx.c',
        'mkvarr.c',
        'rdffdi.c',
        'zztrgnvx.c',
        'mkgrid.c',
        'wrtdsk.c',
        'zzpsxtnt.c',
        'rc2cor.c',
        'prcinf.c',
        'rdffpl.c',
        'zzvoxscl.c',
        'prcset.c',
        'zzwseg02.c',
         ],
   include_directories : includes)

mkdsk = executable(
    'mkdsk', [ 'mkdsk.c', 'main.c' ],
    include_directories : includes,
    link_with : [ libmkdsk, libcsupport, libcspice ],
    dependencies : [ math_dep ],
    install : true)
