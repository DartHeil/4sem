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
      std::cout << word << "\n";
//    mapT::iterator  it= words.find(word);
//    if( it != my_map.end() )
      if (!word.empty())
        words[word]++;
      word = "";
//      it->second++;
//    else
//      words.insert( pair<char,int>(word,1) );
    }
  }
  
  file.close();
  return words;
} 

std::vector<statistics> vector_create(mapT words)
{
  int i = 0;
  std::vector<statistics> vwords(10);
  statistics wordstat;
  
  for (mapT::iterator it = words.begin(); it != words.end(); it++)
  {
    wordstat.word = (*it).first;
    std::cout << wordstat.word << "\n";
    wordstat.count = (*it).second;
    std::cout << wordstat.count << "\n";
    vwords.push_back(wordstat);
  }

  return vwords;
}

bool comparator(const statistics& lhs, const statistics& rhs)
{
	return lhs.count < rhs.count ? true : false;
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
//  std::ostream_iterator<statistics> out(std::cout);
  std::sort(vwords.begin(), vwords.end(), comparator); 
  //std::copy(vwords.begin(), vwords.end(), out);

  int num = (words_amount < vwords.size()) ? words_amount : vwords.size();
  for (int i = 0; i < num; i++)
    output << vwords[i].count << " " << vwords[i].word << std::endl;

  output.close();      
  return 0;
}

 
 
