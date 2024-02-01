public class Hello {

    static class TreeNode {

        int val;

        TreeNode left;
        TreeNode right;

        TreeNode() {

        }

        TreeNode(int val) {

            this.val = val;

        }

        TreeNode(int val, TreeNode left, TreeNode right) {

            this.val = val;
            this.left = left;
            this.right = right;

        }

    }

    static int countPseudoPalindromicPaths = 0;

    private static boolean isPathPalindromic(int[] pathFreq) {

        int numberOfOddFreq = 0;

        for (int idx = 0; idx < 10; ++idx) {

            if (pathFreq[idx] % 2 != 0) {

                ++numberOfOddFreq;

            }

        }

        if (numberOfOddFreq <= 1) {

            return true;

        }

        return false;

    }

    private static void allPaths(TreeNode root, int[] pathFreq) {

        if (root == null) {

            return;

        }

        ++pathFreq[root.val - 1];

        if (root.left == null && root.right == null) {

            if (isPathPalindromic(pathFreq)) {

                ++countPseudoPalindromicPaths;

            }

        } else {

            allPaths(root.left, pathFreq);
            allPaths(root.right, pathFreq);

        }

        --pathFreq[root.val - 1];

    }

    public int pseudoPalindromicPaths(TreeNode root) {

        int[] pathFreq = new int[9];

        allPaths(root, pathFreq);

        int count = countPseudoPalindromicPaths;

        countPseudoPalindromicPaths = 0;

        return count;

    }

}
