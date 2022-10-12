/**
 * @SayantanDas
 * 
 * This Class is just dedicated for creating the Composite key for the Model AppointmentSlots
*/


package com.cg.healthreminder.model;
import javax.persistence.*;
import javax.validation.constraints.Min;
import java.io.Serializable;

@Embeddable
public class SlotCompositeKey implements Serializable {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	@Min(1)
	private int doctorId;
	private String doctorDate;
	
	public SlotCompositeKey() {
		super();
	}

	public int getDoctorId() {
		return doctorId;
	}

	public void setDoctorId(int doctorId) {
		this.doctorId = doctorId;
	}

	public String getDoctorDate() {
		return doctorDate;
	}

	public void setDoctorDate(String doctorDate) {
		this.doctorDate = doctorDate;
	}

	public SlotCompositeKey(@Min(1) int doctorId,String doctorDate) {
		super();
		this.doctorId = doctorId;
		this.doctorDate = doctorDate;
	}
	
}
