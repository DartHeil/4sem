#include <iostream>
#include <algorithm>	
#include <string>
#include <map>
#include <fstream>
#include <iterator>
#include <vector>

typedef std::map<std::string,int>  mapT;

struct statistics
{
  int count;
  std::string word;
};

std::string prepare(const std::string& word)
{
  std::string result = "";
  std::string punct = "!@#$%^&*()_-+=\"'|?/\\<>,.;:[]{}“”—…’‘123456789";
  result.resize(word.size());
  std::transform(word.begin(), word.end(), result.begin(), ::tolower);
  long start = 0, end = 0, len = result.length();
  for (start = 0; start < len && punct.find(result[start]) != std::string::npos; start++);
    for (end = len - 1; end >= 0 && punct.find(result[end]) != std::string::npos; end--);
      if (end < start)
        result = "";
      else
        result = result.substr(start, end - start + 1);
  return result;
}

mapT map_create()
{
  std::ifstream file("text.txt");
  mapT words;

  if (file.is_open())
  {
    std::string word;    
    while(!file.eof())
    {
      file >> word;		
      word = prepare(word);

      if (!word.empty())
        words[word]++;
      word = "";
    }
  }
  
  file.close();
  return words;
} 

std::vector<statistics> vector_create(mapT words)
{
  int i = 0;
  std::vector<statistics> vwords(10);
  
  for (mapT::iterator it = words.begin(); it != words.end(); it++)
  {
    vwords[i].word = (*it).first;
    vwords[i].count = (*it).second;
    i++;
  }

  return vwords;
}

bool comparator(const statistics& lhs, const statistics& rhs)
{
  return rhs.count < lhs.count ? true : false;
}

int data_input()
{
  int words_amount = 0;
  std::cout << "Input the amount of words to output" << std::endl;
  std::cin >> words_amount;

  return words_amount;
}
 
int main()
{
  std::ofstream output("output.txt");
  int words_amount = data_input();
  mapT words = map_create();
  std::vector<statistics> vwords = vector_create(words);
  
  std::sort(vwords.begin(), vwords.end(), comparator); 
 
  int num = (words_amount < vwords.size()) ? words_amount : vwords.size();
  for (int i = 0; i < num; i++)
    output << vwords[i].count << " " << vwords[i].word << std::endl;

  output.close(); 
  std::cout << "Successfully completed"<< "\n";     
  return 0;
}
