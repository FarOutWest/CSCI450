// Generated from calculator.g4 by ANTLR 4.7
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link calculatorParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface calculatorVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by the {@code ToSetVar}
	 * labeled alternative in {@link calculatorParser#input}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitToSetVar(calculatorParser.ToSetVarContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Calculate}
	 * labeled alternative in {@link calculatorParser#input}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCalculate(calculatorParser.CalculateContext ctx);
	/**
	 * Visit a parse tree produced by the {@code SetVariable}
	 * labeled alternative in {@link calculatorParser#setVar}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSetVariable(calculatorParser.SetVariableContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ToMultOrDiv}
	 * labeled alternative in {@link calculatorParser#plusOrMinus}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitToMultOrDiv(calculatorParser.ToMultOrDivContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Plus}
	 * labeled alternative in {@link calculatorParser#plusOrMinus}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPlus(calculatorParser.PlusContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Minus}
	 * labeled alternative in {@link calculatorParser#plusOrMinus}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMinus(calculatorParser.MinusContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Multiplication}
	 * labeled alternative in {@link calculatorParser#multOrDiv}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMultiplication(calculatorParser.MultiplicationContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Division}
	 * labeled alternative in {@link calculatorParser#multOrDiv}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDivision(calculatorParser.DivisionContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ToPow}
	 * labeled alternative in {@link calculatorParser#multOrDiv}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitToPow(calculatorParser.ToPowContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Power}
	 * labeled alternative in {@link calculatorParser#pow}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPower(calculatorParser.PowerContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ChangeSign}
	 * labeled alternative in {@link calculatorParser#unaryMinus}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitChangeSign(calculatorParser.ChangeSignContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ToAtom}
	 * labeled alternative in {@link calculatorParser#unaryMinus}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitToAtom(calculatorParser.ToAtomContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConstantPI}
	 * labeled alternative in {@link calculatorParser#atom}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstantPI(calculatorParser.ConstantPIContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConstantE}
	 * labeled alternative in {@link calculatorParser#atom}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstantE(calculatorParser.ConstantEContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Double}
	 * labeled alternative in {@link calculatorParser#atom}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDouble(calculatorParser.DoubleContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Int}
	 * labeled alternative in {@link calculatorParser#atom}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInt(calculatorParser.IntContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Variable}
	 * labeled alternative in {@link calculatorParser#atom}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariable(calculatorParser.VariableContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Braces}
	 * labeled alternative in {@link calculatorParser#atom}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBraces(calculatorParser.BracesContext ctx);
}