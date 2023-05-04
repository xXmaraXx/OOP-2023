#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <map>

/// <summary>
/// imi scapa 2 filme si 1966 are mai multe episoade la mine decat 1965 nu inteleg de ce
/// </summary>

class CsvIterator {
    std::ifstream& file;
    std::vector<std::string> current_row;

  public:
    CsvIterator(std::ifstream& file) : file(file) {
        operator++();
    }
    CsvIterator() : file(*(new std::ifstream())) {
    }

    CsvIterator& operator++() {
        current_row.clear();
        std::string line;
        if (std::getline(file, line)) {
            std::istringstream line_stream(line);
            std::string cell;
            while (std::getline(line_stream, cell, ',')) {
                if (!cell.empty() && cell.front() == '"' && cell.back() == '"') {
                    cell = cell.substr(1, cell.size() - 2);
                }
                current_row.push_back(cell);
            }
        }
        return *this;
    }

    std::vector<std::string> operator*() const {
        return current_row;
    }

    bool operator!=(const CsvIterator& other) const {
        return !file.eof();
    }
};

class CsvReader {
    std::ifstream& file;

  public:
    CsvReader(std::ifstream& file) : file(file) {
    }
    CsvIterator begin() {
        return CsvIterator(file);
    }
    CsvIterator end() {
        return CsvIterator(file);
    }
};

class Episode {
  private:
    std::string title;
    std::string date;
    std::string length;
    float viewersmm;
    double score;

  public:
    Episode(const std::string& title, const std::string& date, std::string& length, float viewersmm, double score)
        : title(title), date(date), length(length), viewersmm(viewersmm), score(score) {}
    std::string get_title() const {
        return title;
    }
    std::string get_date() const {
        return date;
    }

    std::string get_length() const {
        return length;
    }

    float get_viewersmm() const {
        return viewersmm;
    }

    double get_score() const {
        return score;
    }
};

int main() {
    std::ifstream input_file("episodes.csv");
    if (!input_file.is_open()) {
        printf("File couldn't be opened\n");
        return 1;
    }
    CsvReader reader(input_file);

    std::vector<Episode> episodes;
    for (std::vector<std::string> columns : reader) {
        // Transform the columns into an Episode and push it in a vector
        std::string title = columns[0];
        std::string date = columns[1];
        std::string length = columns[2];
        float viewersmm = std::stof(columns[3]);
        double score = std::stod(columns[4]);

        Episode episode(title, date, length, viewersmm, score);
        episodes.push_back(episode);
    }

    printf("number of episodes: %zu\n\n", episodes.size());

    std::ofstream output_file("output.txt");
    for (const auto& episode : episodes) {
        // Pretty print the episode in the output file
        output_file << std::left << std::setw(40) << episode.get_title() << std::setw(15) << episode.get_date()
                    << std::setw(10) << episode.get_length()<< std::setw(10) << episode.get_viewersmm() << std::setw(10) << episode.get_score() << std::endl;
    }

    std::sort(episodes.begin(), episodes.end(), [](const Episode& a, const Episode& b) {
        if (a.get_score() != b.get_score()) {
            return a.get_score() > b.get_score();
        }
        return a.get_title() < b.get_title();
    });

    std::cout << "The 10 most appreciated episodes:" << std::endl;
    for (int i = 0; i < 10 && i < episodes.size(); i++) {
        std::cout << i+1 << ". " << episodes[i].get_score() << " -> " << episodes[i].get_title() << "\n";
    }
    std::cout << "\n";

    std::sort(episodes.begin(), episodes.end(), [](const Episode& a, const Episode& b) {
        if (a.get_length() != b.get_length()) {
            return a.get_length() > b.get_length();
        }
        return a.get_title() < b.get_title();
    });

    std::cout << "The 10 longest episodes:" << std::endl;
    for (int i = 0; i < 10 && i < episodes.size(); i++) {
        std::cout << i+1 << ". " << episodes[i].get_length() << " -> " << episodes[i].get_title() << "\n";
    }
    std::cout << "\n";

    std::map<std::string, int> episodes_per_year;
    for (const auto& episode : episodes) {
        std::string year = episode.get_date().substr(0, 4);
        episodes_per_year[year]++;
    }

    std::string year_with_most_episodes;
    int most_episodes = 0;
    for (const auto& [year, count] : episodes_per_year) {
        if (count > most_episodes) {
            year_with_most_episodes = year;
            most_episodes = count;
        }
    }

    std::cout << "The year " << year_with_most_episodes << " has the most episodes: " << most_episodes << "\n";

    return 0;
}