class Solution {
    private Map<Integer, List<Character>> mp = new HashMap<>();
    private List<String> ans = new ArrayList<>();
    private void prepare_phone(){
        List<Character> L = new ArrayList<>();
        L.add('a');
        L.add('b');
        L.add('c');
        mp.put(2, new ArrayList<>(L));
        L.clear();
        L.add('d');
        L.add('e');
        L.add('f');
        mp.put(3, new ArrayList<>(L));
        L.clear();
        L.add('g');
        L.add('h');
        L.add('i');
        mp.put(4, new ArrayList<>(L));
        L.clear();
        L.add('j');
        L.add('k');
        L.add('l');
        mp.put(5, new ArrayList<>(L));
        L.clear();
        L.add('m');
        L.add('n');
        L.add('o');
        mp.put(6, new ArrayList<>(L));
        L.clear();
        L.add('p');
        L.add('q');
        L.add('r');
        L.add('s');
        mp.put(7, new ArrayList<>(L));
        L.clear();
        L.add('t');
        L.add('u');
        L.add('v');
        mp.put(8, new ArrayList<>(L));
        L.clear();
        L.add('w');
        L.add('x');
        L.add('y');
        L.add('z');
        mp.put(9, new ArrayList<>(L));
        L.clear();
    }
    private void backtrack(int idx, String temp, String digits){
        if(digits.length() == temp.length()){
            ans.add(temp);
            return;
        }
        for(int i=idx;i<digits.length();++i){
            List<Character> str = new ArrayList<>();
            str = mp.get(Character.getNumericValue(digits.charAt(i)));
            for(int j=0;j<str.size();++j){
                temp += str.get(j);
                backtrack(i+1, temp, digits);
                temp = temp.substring(0, temp.length()-1);
            }
        }
        
    }
    public List<String> letterCombinations(String digits) {
        if(digits.isEmpty()){
            return new ArrayList<>();
        }
        prepare_phone();
        String temp = "";
        backtrack(0, temp, digits);
        return ans;
    }
}