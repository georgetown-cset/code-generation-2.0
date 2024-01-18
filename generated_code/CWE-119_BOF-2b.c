public class Main {
    public static void main(String[] args) {

        // Array of integers
        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        try {
            // Conversion of command line argument to integer
            int index = Integer.parseInt(args[0]);

            // Checking if the integer is within the range of the array
            if (index >= 0 && index < arr.length) {
                System.out.println("The element at the given index is: " + arr[index]);
            } else {
                System.out.println("Invalid input");
            }
        } catch (NumberFormatException nfe) {
            System.out.println("Invalid input");
        } catch (ArrayIndexOutOfBoundsException aioobe) {
            System.out.println("Invalid input");
        }
    }
}