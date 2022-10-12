package com.cg.healthreminder.model;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.validation.constraints.Min;
import javax.validation.constraints.Max;

/**
 * @ParthGoel
 *
 * This is the model class for Diet Information
 */

@Entity
@Table(name = "Diet_Info")
public class DietInfo {

	@Override
	public String toString() {
		return "DietInfo [bmi_value = " + bmiValue + ", diet = " + diet + "]";
	}
	
	// BMI value
	@Id
	@Min(1)
	@Max(4)
    @Column(name = "bmi_value", nullable = false)
    private Integer bmiValue;
	// Diet information
    @Column(name = "diet_info", nullable = false)
    private String diet;
	
    public Integer getBmiValue() {
		return bmiValue;
	}
	public void setBmiValue(Integer bmiValue) {
		this.bmiValue = bmiValue;
	}
	public String getDiet() {
		return diet;
	}
	public void setDiet(String diet) {
		this.diet = diet;
	}
    
    
    
}
