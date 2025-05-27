#include <cloudseal/grpc/client.hpp>
#include <QEventLoop>

namespace cloudseal::grpc {

    CloudSealClient::CloudSealClient(const QUrl& endpoint, QObject* parent)
        : QObject(parent)
        , m_channel(std::make_shared<QGrpcHttp2Channel>(endpoint))
    {
        m_stub.attachChannel(m_channel);          // podłączenie kanału do stuba :contentReference[oaicite:0]{index=0}
    }

    /* ---------- proste wrappersy asynchroniczne ------------------------------------------------ */

    std::unique_ptr<QGrpcCallReply> CloudSealClient::registerUser(const AuthRequest& r) { return m_stub.Register(r); }
    std::unique_ptr<QGrpcCallReply> CloudSealClient::login(const AuthRequest& r) { return m_stub.Login(r); }
    std::unique_ptr<QGrpcCallReply> CloudSealClient::uploadVault(const VaultRequest& r) { return m_stub.UploadVault(r); }
    std::unique_ptr<QGrpcCallReply> CloudSealClient::downloadVault(const VaultQuery& r) { return m_stub.DownloadVault(r); }
    std::unique_ptr<QGrpcCallReply> CloudSealClient::uploadFile(const FileTransferPath& r) { return m_stub.UploadFile(r); }
    std::unique_ptr<QGrpcCallReply> CloudSealClient::downloadFile(const FileTransferPath& r) { return m_stub.DownloadFile(r); }
    std::unique_ptr<QGrpcCallReply> CloudSealClient::listFiles(const AuthToken& r) { return m_stub.ListFiles(r); }
    std::unique_ptr<QGrpcCallReply> CloudSealClient::getStats(const AuthToken& r) { return m_stub.GetStats(r); }

    /* ---------- pomocniczy szablon do blokujących wywołań (Unary → CallReply) ------------------ */

    template<class ReqMsg, class RespMsg, class Func>
    static RespMsg waitUnary(Func&& invoker, const ReqMsg& req, QGrpcStatus* out)
    {
        auto reply = std::invoke(std::forward<Func>(invoker), req);   // wywołanie RPC
        QEventLoop loop;
        RespMsg result;                          // pusta odpowiedź na wypadek błędu
        QObject::connect(reply.get(), &QGrpcCallReply::finished, &loop,
            [&](const QGrpcStatus& st) {
                if (out) *out = st;
                if (st.isOk()) {
                    if (auto msg = reply->template read<RespMsg>())
                        result = *msg;
                }
                else emit qobject_cast<QObject*>(reply.get())->parent()->findChild<CloudSealClient*>()->error(st.message());
                loop.quit();
            });
        loop.exec();
        return result;
    }

    /* ---------- implementacje Sync ------------------------------------------------------------- */

    AuthResponse  CloudSealClient::registerUserSync(const AuthRequest& r, QGrpcStatus* s) { return waitUnary<AuthRequest, AuthResponse >([&](auto&& x) { return m_stub.Register(x); }, r, s); }
    AuthResponse  CloudSealClient::loginSync(const AuthRequest& r, QGrpcStatus* s) { return waitUnary<AuthRequest, AuthResponse >([&](auto&& x) { return m_stub.Login(x); }, r, s); }
    Status        CloudSealClient::uploadVaultSync(const VaultRequest& r, QGrpcStatus* s) { return waitUnary<VaultRequest, Status       >([&](auto&& x) { return m_stub.UploadVault(x); }, r, s); }
    VaultResponse CloudSealClient::downloadVaultSync(const VaultQuery& r, QGrpcStatus* s) { return waitUnary<VaultQuery, VaultResponse >([&](auto&& x) { return m_stub.DownloadVault(x); }, r, s); }
    Status        CloudSealClient::uploadFileSync(const FileTransferPath& r, QGrpcStatus* s) { return waitUnary<FileTransferPath, Status>([&](auto&& x) { return m_stub.UploadFile(x); }, r, s); }
    Status        CloudSealClient::downloadFileSync(const FileTransferPath& r, QGrpcStatus* s) { return waitUnary<FileTransferPath, Status>([&](auto&& x) { return m_stub.DownloadFile(x); }, r, s); }
    FileList      CloudSealClient::listFilesSync(const AuthToken& r, QGrpcStatus* s) { return waitUnary<AuthToken, FileList     >([&](auto&& x) { return m_stub.ListFiles(x); }, r, s); }
    GlobalStats   CloudSealClient::getStatsSync(const AuthToken& r, QGrpcStatus* s) { return waitUnary<AuthToken, GlobalStats  >([&](auto&& x) { return m_stub.GetStats(x); }, r, s); }

} // namespace cloudseal
