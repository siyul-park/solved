class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> lines;
        int n = words.size();
        int index = 0;

        while (index < n) {
            int length = words[index].length();
            int last = index + 1;
            while (last < n) {
                if (length + words[last].length() + (last - index) > maxWidth) {
                    break;
                }
                length += words[last].length();
                last++;
            }

            string line;
            int gaps = last - index - 1;

            if (last == n || gaps == 0) {
                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) {
                        line += ' ';
                    }
                }
                while (line.length() < maxWidth) {
                    line += ' ';
                }
            } else {
                int spaces = (maxWidth - length) / gaps;
                int extraSpaces = (maxWidth - length) % gaps;

                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) {
                        int spaceToApply =
                            spaces + (i - index < extraSpaces ? 1 : 0);
                        for (int j = 0; j < spaceToApply; j++) {
                            line += ' ';
                        }
                    }
                }
            }

            lines.push_back(line);
            index = last;
        }

        return lines;
    }
};
