#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <QtGui/QGuiApplication>

#include <grpcpp/grpcpp.h>
#include "cloudseal.grpc.pb.h"

namespace cloudseal {

    using grpc::Channel;
    using grpc::ClientContext;
    using cloudseal::CloudSeal;
    using cloudseal::AuthRequest;
    using cloudseal::AuthResponse;

    class CloudSealClient {
    public:
        CloudSealClient(std::shared_ptr<Channel> channel)
            : stub_(CloudSeal::NewStub(channel)) {
        }

        std::string Register(const std::string& username, const std::string& password) {
            AuthRequest request;
            request.set_username(username);
            request.set_password(password);

            AuthResponse reply;
            ClientContext context;

            auto status = stub_->Register(&context, request, &reply);

            if (status.ok() && reply.success()) {
                std::cout << "Rejestracja udana. Token: " << reply.token() << std::endl;
                return reply.token();
            }
            else {
                std::cout << "Rejestracja nieudana: " << reply.message() << std::endl;
                return "";
            }
        }

        std::string Login(const std::string& username, const std::string& password) {
            AuthRequest request;
            request.set_username(username);
            request.set_password(password);

            AuthResponse reply;
            ClientContext context;

            auto status = stub_->Login(&context, request, &reply);

            if (status.ok() && reply.success()) {
                std::cout << "Logowanie udane. Token: " << reply.token() << std::endl;
                return reply.token();
            }
            else {
                std::cout << "Logowanie nieudane: " << reply.message() << std::endl;
                return "";
            }
        }

        bool UploadVault(const std::string& token, const std::string& vault_path) {
            VaultRequest request;
            request.set_token(token);

            // Wczytaj zawartość pliku vault
            std::ifstream file(vault_path, std::ios::binary);
            if (!file) {
                std::cerr << "Nie można otworzyć pliku vault: " << vault_path << std::endl;
                return false;
            }
            std::string vault_data((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
           // request.set_vaultdata(vault_data);

            cloudseal::Status reply;
            ClientContext context;

            auto status = stub_->UploadVault(&context, request, &reply);

            if (status.ok() && reply.success()) {
                std::cout << "Vault przesłany pomyślnie." << std::endl;
                return true;
            }
            else {
                std::cout << "Błąd podczas przesyłania vault: " << reply.message() << std::endl;
                return false;
            }
        }

        bool DownloadVault(const std::string& token, const std::string& output_path) {
            VaultQuery request;
            request.set_token(token);

            VaultResponse reply;
            ClientContext context;

            auto status = stub_->DownloadVault(&context, request, &reply);

            if (status.ok()) {
                // Zapisz dane vault do pliku
                std::ofstream file(output_path, std::ios::binary);
                if (!file) {
                    std::cerr << "Nie można otworzyć pliku do zapisu: " << output_path << std::endl;
                    return false;
                }
               // file.write(reply.vaultdata().data(), reply.vaultdata().size());
                std::cout << "Vault pobrany i zapisany do: " << output_path << std::endl;
                return true;
            }
            else {
                std::cout << "Błąd podczas pobierania vault: " << status.error_message() << std::endl;
                return false;
            }
        }

    private:
        std::unique_ptr<CloudSeal::Stub> stub_;
    };
}

int main2(int argc, char** argv) {
    cloudseal::CloudSealClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));

    std::string username = "user1";
    std::string password = "securepassword";

    // Rejestracja
    std::string token = client.Register(username, password);
    if (token.empty()) {
        // Jeśli rejestracja nie powiodła się, spróbuj zalogować się
        token = client.Login(username, password);
        if (token.empty()) {
            std::cerr << "Nie udało się zarejestrować ani zalogować." << std::endl;
            return 1;
        }
    }

    // Ścieżka do pliku vault
    std::string vault_path = "vault.seal";

    // Przesyłanie vault
    if (!client.UploadVault(token, vault_path)) {
        std::cerr << "Błąd podczas przesyłania vault." << std::endl;
        return 1;
    }

    // Pobieranie vault
    std::string output_path = "downloaded_vault.seal";
    if (!client.DownloadVault(token, output_path)) {
        std::cerr << "Błąd podczas pobierania vault." << std::endl;
        return 1;
    }

    return 0;
}
