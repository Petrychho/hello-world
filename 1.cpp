void join(const std::vector< int > &from, std::vector< int > &to)
{
	std::vector<int> out;
	out.reserve(from.size() + to.size());

	std::merge(from.begin(), from.end(),
		to.begin(), to.end(),
		std::back_inserter(out));
	
	to = out;
};
