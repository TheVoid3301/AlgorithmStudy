class Solution {
    public int maxFreqSum(String s) {
        // 用于统计元音字母频率的 map
        Map<Character, Integer> vowelMap = new HashMap<>();
        // 用于统计辅音字母频率的 map
        Map<Character, Integer> consonantMap = new HashMap<>();

        // 定义元音字母
        String vowels = "aeiou";

        // 遍历字符串中的每个字符
        for (char c : s.toCharArray()) {
            if (vowels.indexOf(c) != -1) {
                // 是元音
                vowelMap.put(c, vowelMap.getOrDefault(c, 0) + 1);
            } else {
                // 是辅音
                consonantMap.put(c, consonantMap.getOrDefault(c, 0) + 1);
            }
        }

        // 找出元音中出现频率最高的次数
        int maxVowelFreq = 0;
        for (int freq : vowelMap.values()) {
            maxVowelFreq = Math.max(maxVowelFreq, freq);
        }

        // 找出辅音中出现频率最高的次数
        int maxConsonantFreq = 0;
        for (int freq : consonantMap.values()) {
            maxConsonantFreq = Math.max(maxConsonantFreq, freq);
        }

        // 返回两者最大频率之和
        return maxVowelFreq + maxConsonantFreq;
    }
}