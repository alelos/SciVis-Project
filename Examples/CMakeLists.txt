# declare directories containing used libraries
LINK_DIRECTORIES(${dcmimage_BINARY_DIR} ${ofstd_BINARY_DIR} ${oflog_BINARY_DIR} ${dcmdata_BINARY_DIR} ${dcmimgle_BINARY_DIR} ${ZLIB_LIBDIR} ${LIBTIFF_LIBDIR} ${LIBPNG_LIBDIR})

# declare executables
FOREACH(PROGRAM dcmtk )
  ADD_EXECUTABLE(${PROGRAM} ${PROGRAM})
ENDFOREACH(PROGRAM)


# make sure executables are linked to the corresponding libraries
FOREACH(PROGRAM dcmtk )
  TARGET_LINK_LIBRARIES(${PROGRAM} dcmimage dcmimgle dcmdata oflog ofstd )
ENDFOREACH(PROGRAM)
#TARGET_LINK_LIBRARIES(dcm2pnm ${LIBTIFF_LIBS} ${LIBPNG_LIBS})
