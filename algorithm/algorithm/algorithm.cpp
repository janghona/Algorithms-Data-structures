#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

typedef __int64 bigint;

int HashFunction(string str)
{
	bigint hashValue = 0;

	for (int i = 0; i < str.length(); i++)
		hashValue += str[i] * pow(101.0, str.length() - 1 - i);

	return hashValue % 101;
}

int HashFunction(string str, bigint& hashValue)
{
	for (int i = 0; i < str.length(); i++)
		hashValue += str[i] * pow(101.0, str.length() - 1 - i);

	return hashValue % 101;
}

int RollingHashFunction(bigint& hashValue, int oldChar, int newChar, int patternLength)
{
	hashValue = (hashValue - (oldChar * pow(101.0, patternLength - 1))) * 101 + newChar;

	return hashValue % 101;
}

bool RabinKarp(string text, string pattern)
{
	bool result = false;

	int patternResult = HashFunction(pattern);
	bigint hashValue = 0;
	int textResult = HashFunction(text.substr(0, pattern.length()), hashValue);

	for (int i = 0; i < text.length() - pattern.length() + 1; i++)
	{
		if (textResult == patternResult)
		{
			if (text.substr(i, pattern.length()) == pattern)
			{
				cout << "Found " << text.substr(i, pattern.length()) << " in " << i << " Index." << endl;
				result = true;
			}
		}

		textResult = RollingHashFunction(hashValue, text[i], text[i + pattern.length()], pattern.length());
	}

	return result;
}

bool RabinKarp(string text, unordered_set<string> stringSet, int maxLength)
{
	bool result = false;

	unordered_set<int> hashSet;
	for (auto& str : stringSet)
		hashSet.insert(HashFunction(str));

	bigint hashValue = 0;
	int textResult = HashFunction(text.substr(0, maxLength), hashValue);

	for (int i = 0; i < text.length() - maxLength; i++)
	{
		if (hashSet.count(textResult))
		{
			unordered_set<string>::iterator it = stringSet.find(text.substr(i, maxLength));
			if (it != stringSet.end())
			{
				cout << "Found " << text.substr(i, maxLength) << " in " << i << " Index." << endl;
				result = true;
			}
		}

		textResult = RollingHashFunction(hashValue, text[i], text[i + maxLength], maxLength);
	}

	return result;
}

int main()
{
	string text = "Rabin-Karp algorithm From Wikipedia, the free encyclopedia\n"
		"In computer science, the Rabin-Karp algorithm or Karp-Rabin algorithm\n"
		"is a string searching algorithm created by Richard M. Karp and Michael O.\n"
		"Rabin (1987) that uses hashing to find any one of a set of pattern strings in a text.\n"
		"For text of length n and p patterns of combined length m,\nits average and best case running time is O(n+m) in space O(p),\n"
		"but its worst-case time is O(nm).\n"
		"In contrast, the Aho-Corasick string matching algorithm has asymptotic worst-time complexity O(n+m) in space O(m).\n"
		"A practical application of the algorithm is detecting plagiarism. Given source material,\n"
		" the algorithm can rapidly search through a paper for instances of sentences from the source material,\n"
		"ignoring details such as case and punctuation.\n"
		"Because of the abundance of the sought strings, single-string searching algorithms are impractical.\n";

	cout << text << endl << endl;

	cout << "Find Single Pattern" << endl;
	RabinKarp(text, "Rabin");
	RabinKarp(text, "Karp");
	cout << endl;

	unordered_set<string> stringSet;
	stringSet.insert("Rabin");
	stringSet.insert("Karp ");

	cout << "Find Mutliple Pattern" << endl;
	RabinKarp(text, stringSet, 5);

	return 0;
}