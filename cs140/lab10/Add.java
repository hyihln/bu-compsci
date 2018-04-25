package lab10;

public class Add extends Expr {
    private Expr left;
    private Expr right;

    public Add(Expr left, Expr right) {
        this.left = left;
        this.right = right;
    }

    public int eval() {
        return left.eval() + right.eval();
    }

	@Override
	public String toString() {
		return "("+left+" + "+right+")";
	}
}