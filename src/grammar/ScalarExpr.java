package grammar;

/**
 * ScalarExpr
 * Creation date: (3/3/2003 2:28:43 AM)
 * @author: mattia parigiani, Sorin Stancu-Mara, Andrei Aiordachioaie
 */

public class ScalarExpr implements IParseTreeNode {
	IParseTreeNode expr;

	public ScalarExpr(IParseTreeNode e) {
	    expr = e;
	}

	public String toXML(){
		return expr.toXML();
	}

}
