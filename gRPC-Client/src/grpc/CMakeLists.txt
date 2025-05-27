# src/grpc/CMakeLists.txt
set(CLOUDSEAL_PROTO "${CMAKE_CURRENT_SOURCE_DIR}/proto/cloudseal.proto")

add_library(CloudSealProtos STATIC)

# 1) Jeden, wspólny target biblioteki z wiadomościami *i* klientem gRPC
qt_add_protobuf(CloudSealProtos         # <-- nazwa biblioteki / targetu
    PROTO_FILES ${CLOUDSEAL_PROTO}
    GENERATE_PACKAGE_SUBFOLDERS         # <cloudseal/...>.h jeśli używasz package cloudseal;
)

qt_add_grpc(CloudSealProtos CLIENT      # <-- ten sam target!
    PROTO_FILES ${CLOUDSEAL_PROTO}
    GENERATE_PACKAGE_SUBFOLDERS
)

# 2) Dołącz moduły Qt potrzebne do linkowania
target_link_libraries(CloudSealProtos
    PUBLIC               # propaguje include-dir i link-liby dalej
        Qt6::Protobuf
        Qt6::Grpc
)

# 3) Upewnij się, że wygenerowane nagłówki są widoczne
target_include_directories(CloudSealProtos
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
)
