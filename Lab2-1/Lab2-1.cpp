#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class HTMLGenerator {
private:
    std::vector<std::string> content;

public:
    void addTitle(const std::string& text) {
        content.push_back("<t>" + text + "</t>");
    }
    void addParagraph(const std::string& text) {
        content.push_back("<p>" + text + "</p>");
    }

    void addHeading(const std::string& text, int level = 1) {
        content.push_back("<h" + std::to_string(level) + ">" + text + "</h" + std::to_string(level) + ">");
    }

    void addTable(const std::vector<std::vector<std::string>>& data) {
        std::string table = "<table>";
        for (const auto& row : data) {
            table += "<tr>";
            for (const auto& cell : row) {
                table += "<th>" + cell + "</th>";
            }
            table += "</tr>";
        }
        table += "</table>";
        content.push_back(table);
    }

    void addList(const std::vector<std::string>& items) {
        std::string list = "<ul>";
        for (const auto& item : items) {
            list += "<li>" + item + "</li>";
        }
        list += "</ul>";
        content.push_back(list);
    }

    void saveToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << getHTML();
            file.close();
        }
        else {
            std::cout << "Неудалось открыть файл для записи: " << filename << std::endl;
        }
    }

    std::string getHTML() const {
        std::string html;
        for (const auto& line : content) {
            html += line + "\n";
        }
        return html;
    }

    void display() const {
        std::cout << getHTML() << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    HTMLGenerator html;
    html.addTitle("Пример html-страницы");
    html.addHeading("Информация по задаче");
    html.addParagraph("UUID: ec49b439-45a7-4e2d-9ed0-33aea1a02ec3");
    html.addTable({ {"UUID"} });
    html.addTable({ {"Агрегат"} });
    html.addTable({ {"Номер документа поставки"} });
    html.addTable({ {"Сотрудник"} });
    html.addTable({ {"Описание"} });
    html.addTable({ {"Дата создания"} });
    html.addList({ "Элемент списка 1" });
    html.addList({ "Элемент списка 2" });
    html.addList({ "Элемент списка 3" });
    html.addList({ "Элемент списка 4" });
    html.saveToFile("Простая html-страница");
    html.display();

    return 0;
}
