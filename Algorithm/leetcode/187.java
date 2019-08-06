//https://leetcode.com/problems/repeated-dna-sequences/
//https://1ilsang.blog.me/221607986460

class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        HashMap<String, Integer> hashMap = new HashMap<>();
        List<String> ret = new LinkedList<>();

        for(int i = 0; i <= s.length() - 10; i++) {
            String key = s.substring(i, i + 10);
            if(hashMap.containsKey(key)) {
                int value = hashMap.get(key) + 1;
                hashMap.put(key, value);
                if(value == 2) ret.add(key);
            }
            else hashMap.put(key, 1);
        }

        return ret;
    }
}
