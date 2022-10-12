/**
 * @SayantanDas
 * 
 * This is the ErrorMessage Class which is used to set user defined & understandable messages and errorcodes
*/


package com.cg.healthreminder.exception;


public class ErrorMessage {
	private Integer errorCode;
	private String errorMessge;
	public Integer getErrorCode() {
		return errorCode;
	}
	public void setErrorCode(Integer errorCode) {
		this.errorCode = errorCode;
	}
	public String getErrorMessage() {
		return errorMessge;
	}
	public void setErrorMessage(String errorMessage) {
		this.errorMessge = errorMessage;
	}
	
	

}
