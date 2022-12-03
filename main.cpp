#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

int random_value(){
    const int max_value = 100;

	std::srand(std::time(nullptr));
	const int random_value = std::rand() % 100;
	return random_value;
}

int high_scores(std::string username, int attempts_count){
    const std::string high_scores_filename = "high_scores.txt";
	    {
		    std::ofstream out_file{high_scores_filename, std::ios_base::app};
		    if (!out_file.is_open()) {
			    std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
			    return -1;
		    }
		    out_file << username << ' ';
		    out_file << attempts_count;
		    out_file << std::endl;
	    } 
	    {
		    std::ifstream in_file{high_scores_filename};
		    if (!in_file.is_open()) {
			    std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
			    return -1;
		    }
		    std::cout << "High scores table:" << std::endl;
		    std::string username;
		    int high_score = 0;
		    while (true) {
			    in_file >> username;
			    in_file >> high_score;
    			in_file.ignore();
    			if (in_file.fail()) {
	    			break;
		    	}
			    std::cout << username << '\t' << high_score << std::endl;
            }
	    }
	return 0;
}

int main() {

	int target_value = random_value();
	int current_value = 0;
    int attempts_count=0;
    std::string username;
    std::cout << "Hi! Enter your name, please: ";
    std::cin >> username;
	std::cout << "Enter your guess:" << std::endl;
	do {
		std::cin >> current_value;
        attempts_count++;
		if (current_value > target_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else if (current_value < target_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else {
			std::cout << "you win!" << std::endl;
			break;
		}

	} while(true);
    high_scores (username,attempts_count);
	return 0;
}