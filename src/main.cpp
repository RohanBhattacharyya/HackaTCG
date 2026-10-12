#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <iostream>
#include <ctime>
#include "../include/external/httplib.h"
#include "../include/external/json.hpp"

int main(int, char**){
    std::cout << "Hello, from HackaTCG!\n";
    httplib::Server svr;
    std::string access_token = "NONE";

    const std::string CLIENT_ID = "rkIybDZKGqcoWOA-XNZ9sFLmMbHJpYFXxk7ZOFAx-Is";
    httplib::Client cli("https://hackatime.hackclub.com");

    // httplib::Params params = {
    //     {"client_id", CLIENT_ID},
    //     {"redirect_uri", "localhost:8080/code"},
    //     {"response_type", "code"}
    // };

    // httplib::Result r = cli.Get("/oauth/authorize", params);

    svr.Get("/code", [&CLIENT_ID, &cli, &access_token](const httplib::Request &req, httplib::Response &res){
        res.set_content("You can now close this tab.", "text/plain");
        std::string code = req.get_param_value("code");
        std::cout << code << std::endl;

        httplib::Params params = {
            {"client_id", CLIENT_ID},
            {"code", code},
            {"redirect_uri", "http://localhost:8080/code"},
            {"grant_type", "authorization_code"}
        };

        httplib::Result result = cli.Post("/oauth/token", params);

        nlohmann::json data = nlohmann::json::parse(result->body);
        data.at("access_token").get_to(access_token);

        std::cout << access_token << std::endl;
    });

    svr.Get("/getInfo", [&cli, &access_token](const httplib::Request &req, httplib::Response &res){
        std::string type = req.get_param_value("type");
        if (access_token != "NONE") {
            if (type == "time") {
                cli.set_bearer_token_auth(access_token);
                httplib::Result r = cli.Get("/api/v1/authenticated/hours");
                res.set_content(r->body, "application/json");
            }
        } else {
            res.set_content("{\"total_seconds\":-1}", "application/json");
        }
    });

    if (!svr.set_mount_point("/", "../public")) {
        std::cerr << "Failed to mount the directory" << std::endl;
        return 1;
    }

    svr.listen("0.0.0.0", 8080);
}