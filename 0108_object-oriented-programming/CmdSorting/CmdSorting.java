public class CmdSorting {
	public static void main(String args[]) {
            int itemsCount = args.length;
            int unsortedItems[] = new int[itemsCount];
            
            // Load numbers from args to array
            for (int i = 0; i < itemsCount; i++) {
                unsortedItems[i] = Integer.parseInt(args[i]);
            }
            
            // Bubble Sort
            for (int i = 0; i < unsortedItems.length; i++) {
               for (int j = 0; j < itemsCount-1; j++) {
                    if (unsortedItems[j] > unsortedItems[j+1]) {
                        int temp = unsortedItems[j];
                        unsortedItems[j] = unsortedItems[j+1];
                        unsortedItems[j+1] = temp;
                    }
                }
            }
            
            // Print result
            System.out.print("\n\nSorted numbers:\n");
            for (int i = 0; i < unsortedItems.length; i++) {
                System.out.print(unsortedItems[i]+",");
            }
	}
}





