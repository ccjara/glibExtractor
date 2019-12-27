#ifndef GLIB_GLIB_FILE_HXX
#define GLIB_GLIB_FILE_HXX

#include <string>
#include <vector>

class glib_file {
private:
    std::string label;
    std::vector<char> data;
    std::vector<char>::size_type size;
public:
    glib_file(std::string&& label, std::vector<char>&& data);
    explicit glib_file(
        std::string&& label,
        std::vector<char>::size_type size = 0
    );
    glib_file();

    void rename(std::string&& l) noexcept;
    void rename(const char *l);

    void set_data(std::vector<char>&& d);

    void set_size(std::vector<char>::size_type s) noexcept;
    [[nodiscard]] std::vector<char>::size_type get_size() const noexcept;

    [[nodiscard]] const std::string& get_label() const noexcept;
    // TODO: improve naming (get_data().data() is confusing)
    [[nodiscard]] const std::vector<char>& get_data() const noexcept;

    [[nodiscard]] bool has_data() const noexcept;
    [[nodiscard]] bool has_label() const noexcept;
};

#endif
