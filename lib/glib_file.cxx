#include "glib_file.hxx"

glib_file::glib_file(std::string&& label, std::vector<char>&& dat) :
    label(std::move(label)),
    data(std::move(dat))
    {
    size = data.size();
}

glib_file::glib_file(
    std::string&& label,
    std::vector<char>::size_type size
) :
    label(std::move(label)),
    size(size) {
}

glib_file::glib_file() :
    size(0) {
}

void glib_file::rename(std::string&& l) noexcept {
    label = std::move(l);
}

void glib_file::rename(const char* l) {
    label = l;
}

void glib_file::set_data(std::vector<char>&& d) {
    data = std::move(d);
    size = data.size();
}

const std::string& glib_file::get_label() const noexcept {
    return label;
}

const std::vector<char>& glib_file::get_data() const noexcept {
    return data;
}

bool glib_file::has_data() const noexcept {
    return !data.empty();
}

bool glib_file::has_label() const noexcept {
    return !label.empty();
}

void glib_file::set_size(const std::vector<char>::size_type s) noexcept {
    size = s;
}

std::vector<char>::size_type glib_file::get_size() const noexcept {
    return size;
}
