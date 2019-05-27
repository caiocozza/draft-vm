//  Created by Caio Cozza Vilarinho [caiocozza.art@gmail.com] on 23/05/2019.

#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <any>
#include <sstream>

template<typename T>
class opcode {
    const std::string name;
    const unsigned int code;
    T func;
    
public:
    opcode(const unsigned int code_p, const std::string& name_p, const T&& func_p) noexcept :
    code(code_p), name(name_p), func(std::move(func_p)) {}
    
    template<typename ...U>
    auto Func(const U... params) const noexcept {
        return func(params...);
    }
    
    const opcode<T>& get_me() const noexcept {
        return *this;
    }
};

class vm {
    std::vector<std::string> program;
    
    void create_program_container(const std::string& program_str) noexcept {
        std::istringstream stream_file(program_str);
        std::string line;
        while(std::getline(stream_file, line)) {
            program.push_back(line);
        }
    }
public:
    explicit vm(const std::string& program_str) noexcept {
        if(program_str.empty())
            return;
        
        create_program_container(program_str);
    }
    
    explicit vm(const std::vector<std::string>& program_container) noexcept :
    program(std::move(program_container)) {}
    
public:
    static const inline auto sum_all = opcode(0x01, "sum_all", [] (const auto... params) -> auto {
        return (params+...);
    }).get_me();
};

int main(int argc, const char * argv[]) {
    
    std::tuple<int, double> tp_test(1, 2.2);
    auto res = std::apply([](auto &&... args) { return vm::sum_all.Func(args...); }, tp_test);
    std::cout << res << std::endl;
    return 0;
}
