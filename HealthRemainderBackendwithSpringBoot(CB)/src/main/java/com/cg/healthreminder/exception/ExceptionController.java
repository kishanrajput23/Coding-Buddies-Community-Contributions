/**
 * @SayantanDas
 * 
 * This is the ExceptionController class which handles all Controller and Application level Exceptions
*/

package com.cg.healthreminder.exception;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RestControllerAdvice;

@RestControllerAdvice
public class ExceptionController {
	
	
	/**
	 * 
	 * This method handles Controller level exceptions
	*/

	@ExceptionHandler(AllCustomException.class)
	public ResponseEntity<ErrorMessage> handleProductNotFoundException(AllCustomException ex) {
		ErrorMessage error = new ErrorMessage();
		error.setErrorCode(HttpStatus.NOT_FOUND.value());
		error.setErrorMessage(ex.getMessage());
		return new ResponseEntity<ErrorMessage>(error,HttpStatus.OK);
		
	}
	
	
	/**
	 * 
	 * This method handles Application level generalized exceptions
	*/
	@ExceptionHandler(Exception.class)
	public ResponseEntity<String> handleException(Exception ex) {
		return new ResponseEntity<String>(ex.getMessage(),HttpStatus.BAD_REQUEST);
		
	}
	
	
}
