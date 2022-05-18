import java.util.HashSet;
import java.util.Set;

public class TestHashSet {
    public static void main(String[] args){
        Set<String> set = new HashSet<>();
        set.add("luck");
        set.add("aurora");
        set.add("fairy");
        set.add("happy");
        set.add("candy");
        System.out.println(set);

        for(String s:set){
            System.out.print(s.toUpperCase() + " ");
        }
        System.out.println();
        set.forEach(e -> System.out.print(e.toLowerCase() + " "));
    }
}
