/**
 * @SayantanDas
 * 
 * This is the Custom Exception class which receives the thrown exception message.
*/

package com.cg.healthreminder.exception;

public class AllCustomException extends Exception {
	private static final long serialVersionUID = 1L;

	public AllCustomException(String msg){
		super(msg);
	}
}
