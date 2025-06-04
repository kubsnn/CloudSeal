
#include "cloudseal/grpc/cloudseal.qpb.h"

#include <QtProtobuf/qprotobufregistration.h>

namespace cloudseal::grpc {
static QtProtobuf::ProtoTypeRegistrar ProtoTypeRegistrarCloudFile(qRegisterProtobufType<CloudFile>);
static QtProtobuf::ProtoTypeRegistrar ProtoTypeRegistrarFileList(qRegisterProtobufType<FileList>);
static QtProtobuf::ProtoTypeRegistrar ProtoTypeRegistrarAuthRequest(qRegisterProtobufType<AuthRequest>);
static QtProtobuf::ProtoTypeRegistrar ProtoTypeRegistrarAuthResponse(qRegisterProtobufType<AuthResponse>);
static QtProtobuf::ProtoTypeRegistrar ProtoTypeRegistrarAuthToken(qRegisterProtobufType<AuthToken>);
static QtProtobuf::ProtoTypeRegistrar ProtoTypeRegistrarVaultRequest(qRegisterProtobufType<VaultRequest>);
static QtProtobuf::ProtoTypeRegistrar ProtoTypeRegistrarVaultQuery(qRegisterProtobufType<VaultQuery>);
static QtProtobuf::ProtoTypeRegistrar ProtoTypeRegistrarVaultResponse(qRegisterProtobufType<VaultResponse>);
static QtProtobuf::ProtoTypeRegistrar ProtoTypeRegistrarFileTransferPath(qRegisterProtobufType<FileTransferPath>);
static QtProtobuf::ProtoTypeRegistrar ProtoTypeRegistrarGlobalStats(qRegisterProtobufType<GlobalStats>);
static QtProtobuf::ProtoTypeRegistrar ProtoTypeRegistrarStatus(qRegisterProtobufType<Status>);
static bool RegisterCloudsealProtobufTypes = [](){ qRegisterProtobufTypes(); return true; }();
} // namespace cloudseal::grpc

