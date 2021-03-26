#include "crow/crow_all.h"
#include "motor.h"

int main() {
    crow::SimpleApp app;
    if(!Motor::Instance().init()) {
        std::cout << "motor init failed " << std::endl;
        return -1;
    }
    CROW_ROUTE(app, "/")
    .methods("GET"_method)
    ([](const crow::request& req){
        std::string cmd = req.url_params.get("cmd");
        Motor *motor = &Motor::Instance();
        if(cmd == "S") {
            motor->clean();
        } else if(cmd == "L") {
            motor->left();
        } else if(cmd == "R") {
            motor->right();
        } else if(cmd == "T") {
            motor->forward();
        } else if(cmd == "B") {
            motor->backward();
        } else if(cmd == "A") {
            motor->loopMode();
        }
        return crow::response{cmd};
    });

    app.port(9001).multithreaded().run();
}
