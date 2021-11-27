version = executable(
    'version', [ 'version.c', 'main.c' ],
    include_directories : includes,
    link_with : [ libcsupport, libcspice ],
    dependencies : [ math_dep ],
    install : true)
