#include "StringUtils.h"

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept {

    // if start negative, set to 0
    if(start < 0){
        start = 0;
    }
    // if end < 0, set to string length
    if(end > str.length()){
        end = str.length();
    }

    // if end is greater than string length, set to string length
    if(end > str.length()){
        end = str.length();
    }
    // if start > end or start >= string lenght or end <= 1, return empty string
    if(start > end || start >= str.length() || end <= 1){
        return "";
    }
    
    std::string ret;
    // for i from start to end add letter from str to ret
    for(size_t i = start; i < end; ++i){
        ret += str[i];
    }
    
    return ret;
}

std::string Capitalize(const std::string &str) noexcept {
    //check if empty
    if(str == ""){
        return "";
    } 

    //ret = str
    std::string ret = str;
    //set first letter to upper
    ret[0] = toupper(ret[0]);

    for(size_t i = 1; i < ret.length(); ++i){

        //set each letter to lower
        ret[i] = tolower(ret[i]);
    }

    return ret;
}

std::string Upper(const std::string &str) noexcept {
    //check if empty
    if(str == ""){
        return "";
    } 

    std::string ret = str;
    //start at 0 go until str length while setting each letter to upper
    for(int i = 0; i < ret.length(); ++i){
        ret[i] = toupper(ret[i]);
    }
    return ret;
}

std::string Lower(const std::string &str) noexcept {
    //check if empty
    if(str == ""){
        return "";
    } 

    std::string ret = str;
    //start at 0 go until str length while setting each letter to upper
    for(int i = 0; i < ret.length(); ++i){
        ret[i] = tolower(ret[i]);
    }
    return ret;
}

std::string LStrip(const std::string &str) noexcept {

    size_t offset = 0;

    // Find first non-whitespace character starting from beginning
    for(size_t i = 0; i < str.length(); ++i){
        // if to find whitespace
        if(str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\r' && str[i] != '\f' && str[i] != '\v'){
            offset = i;
            break;
        }
    }
    return std::string(str.begin() + offset, str.end());
}

std::string RStrip(const std::string &str) noexcept {
    size_t end = str.length();

    // Find first non-whitespace character starting from end
    for(size_t i = str.length() - 1; i > 0; --i){
        if(str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\r' && str[i] != '\f' && str[i] != '\v'){
            end = i + 1;
            break;
        }
    }
    return std::string(str.begin(), str.begin() + end);
}

std::string Strip(const std::string &str) noexcept {
    //Strip from both sides
    return RStrip(LStrip(str));
}

std::string Center(const std::string &str, int width, char fill) noexcept {
    //if string wider or equal to width, then don't need to add anything
    if (str.length() >= width){
        return str;
    }

    //get how desired characters
    int offset = width - str.length();
    //get how many characters to add to left and right
    int left = offset / 2;
    int right = offset - left;

    //return string with characters on both sides
    return std::string(left, fill) + str + std::string(right, fill);
}

std::string LJust(const std::string &str, int width, char fill) noexcept {
    //if string wider or equal to width, then don't need to add anything
    if(str.length() >= width){
        return str;
    }
    //return string with width many fill characters on right
    return str + std::string(width - str.length(), fill);
}

std::string RJust(const std::string &str, int width, char fill) noexcept {
    //if string wider or equal to width, then don't need to add anything
    if (str.length() >= width){
        return str;
    }
    //return witdth many fill characters then string
    return std::string(width - str.length(), fill) + str;
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept {
    std::string ret;
    size_t i = 0;
    
    while(i < str.length()){

        bool match = true;

        //finding old in str
        for(size_t j = 0; j < old.length(); ++j){
            //if offset greater than string length or letter doesn't match -> break
            if(i + j >= str.length() || str[i + j] != old[j]){
                match = false;
                break;
            }
        }

        //if true add rep to ret and increase i by old.length()
        if(match == true){
            ret += rep;
            i += old.length();
        }
        //add letter to ret and increment i
        else{
            ret += str[i];
            i++;
        }
    }
    return ret;
}

std::vector<std::string> Split(const std::string &str, const std::string &splt) noexcept {
    std::vector<std::string> ret;
    size_t start = 0;
    
    for(size_t i = 0; i <= str.length(); ++i){
        bool match = true;

        for(size_t j = 0; j < splt.length(); ++j){
            //if offset greater than string length or letter doesn't match -> break
            if(i + j >= str.length() || str[i + j] != splt[j]){
                match = false;
                break;
            }
        }
        if (match == true || i == str.length()){
            //add string to ret vector
            ret.push_back(std::string(str.begin() + start, str.begin() + i));

            //update start to after word added to ret
            start = i + splt.length();
            //update i to after word added to ret. -1 bc i will increment in the loop
            i += splt.length() - 1;
        }
    }
    return ret;
}

std::string Join(const std::string &str, const std::vector<std::string> &vect) noexcept {
    std::string ret;

    // goes through each string in vect and adds to ret with str in between
    for (size_t i = 0; i < vect.size(); ++i) {

        //adds string to ret
        ret += vect[i];

        //check for last string, add str
        if (i != vect.size() - 1){
            ret += str;
        }
    }
    return ret;
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept {
    std::string ret;
    
    //go through each letter in str
    for(size_t i = 0; i < str.length(); ++i){

        //if letter is tab
        if(str[i] == '\t'){
            //add tabsize many space to ret
            ret += std::string(tabsize, ' ');
        }

        else{
            //add letter to ret
            ret += str[i];
        }
    }
    
    return ret;
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept {
    
    //if strings are the same skip everything
    if(right == left){
        return 0;
    }

    //if one empty return length of other
    if(left.length() == 0){
        return right.length();
    }
    if(right.length() == 0){
        return left.length();
    }

    //vector of 0s length of word + 1 for empty
    //ex. "kai" -> 4
    // "", "k", "ka", "kai"
    std::vector<int> prev(right.length() + 1, 0);
    std::vector<int> curr(right.length() + 1, 0);

    //initialize prev
    for(size_t i = 0; i <= right.length(); ++i){
        prev[i] = i;
    }

    //loop through each letter in left. start at 1 to left length
    for(size_t i = 1; i <= left.length(); ++i){
        
        //sets cost of changing first letter
        curr[0] = i;

        //loop through each letter in right. start at 1 to right length
        for(size_t j = 1; j <= right.length(); ++j){

            
            char a = left[i - 1];
            char b = right[j - 1];

            if(ignorecase == true){
                a = tolower(a);
                b = tolower(b);
            }

            //if letters are the same, value of prev[j - 1] used
            if(a == b){
                curr[j] = prev[j - 1];
            }

            //if different, find minimum of removing, inserting, or replacing
            else{
                int rm = prev[j] + 1; //cost remove
                int ins = curr[j - 1] + 1; //cost insert
                int rep = prev[j - 1] + 1; //cost replace

                //find minimum cost and set to curr[j]
                if(rm <= ins && rm <= rep){
                    curr[j] = rm;
                }
                if(ins <= rm && ins <= rep){
                    curr[j] = ins;
                }
                else{
                    curr[j] = rep;
                }

            }
        }

        std::swap(prev, curr);
    }

    return prev[right.length()];
    }
}

