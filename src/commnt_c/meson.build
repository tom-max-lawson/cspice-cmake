libcommnt = static_library(
    'commnt', [
        'clcomm.c',
         ],
   include_directories : includes)

commnt = executable(
    'commnt', [ 'commnt.c', 'main.c' ],
    include_directories : includes,
    link_with : [ libcommnt, libcsupport, libcspice ],
    dependencies : [ math_dep ],
    install : true)
