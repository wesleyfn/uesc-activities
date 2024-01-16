import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception 
    {
        int option;
        Character character = null;
        Scanner scanner = new Scanner(System.in);

        do {
            Menus.mainMenu();
            option = scanner.nextInt();
            switch (option) {
                case 1:
                    String name = scanner.next();
                    character = new Character(name);
                    break;
                case 0:
                    if(character != null) 
                        System.out.println("Tchau, "+character.getName());
                    break;
                default:
                    break;
            }        
        } while (option != 0);
        scanner.close();
    }
}

