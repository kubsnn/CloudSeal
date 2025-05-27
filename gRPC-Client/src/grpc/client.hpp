#pragma once

#include <QtCore/QObject> 
#include <QObject>
#include <memory>
#include <QtGrpc/QGrpcHttp2Channel>
#include <QtGrpc/QGrpcCallReply>
#include <QtGrpc/QGrpcStatus>

#include <cloudseal/grpc/cloudseal.qpb.h>
#include <cloudseal/grpc/cloudseal_client.grpc.qpb.h>   // zamień, jeśli generator dał inną nazwę

namespace cloudseal::grpc {

    class CloudSealClient : public QObject
    {
        Q_OBJECT
    public:
        explicit CloudSealClient(const QUrl& endpoint, QObject* parent = nullptr);

        /* ---------- asynchroniczne wywołania (posiadacz reply zarządza jego życiem) ---------- */
        std::unique_ptr<QGrpcCallReply> registerUser(const AuthRequest&);
        std::unique_ptr<QGrpcCallReply> login(const AuthRequest&);
        std::unique_ptr<QGrpcCallReply> uploadVault(const VaultRequest&);
        std::unique_ptr<QGrpcCallReply> downloadVault(const VaultQuery&);
        std::unique_ptr<QGrpcCallReply> uploadFile(const FileTransferPath&);
        std::unique_ptr<QGrpcCallReply> downloadFile(const FileTransferPath&);
        std::unique_ptr<QGrpcCallReply> listFiles(const AuthToken&);
        std::unique_ptr<QGrpcCallReply> getStats(const AuthToken&);

        /* ---------- wygodne, blokujące wersje (1 → 1 RPC) ------------------------------------ */
        AuthResponse  registerUserSync(const AuthRequest&, QGrpcStatus* st = nullptr);
        AuthResponse  loginSync(const AuthRequest&, QGrpcStatus* st = nullptr);
        Status        uploadVaultSync(const VaultRequest&, QGrpcStatus* st = nullptr);
        VaultResponse downloadVaultSync(const VaultQuery&, QGrpcStatus* st = nullptr);
        Status        uploadFileSync(const FileTransferPath&, QGrpcStatus* st = nullptr);
        Status        downloadFileSync(const FileTransferPath&, QGrpcStatus* st = nullptr);
        FileList      listFilesSync(const AuthToken&, QGrpcStatus* st = nullptr);
        GlobalStats   getStatsSync(const AuthToken&, QGrpcStatus* st = nullptr);

    signals:
        void error(const QString& msg);

    private:
        CloudSeal::Client m_stub;     // kod wygenerowany przez Qt
        std::shared_ptr<QGrpcHttp2Channel> m_channel;  // HTTP/2 transport
    };

} // namespace cloudseal
