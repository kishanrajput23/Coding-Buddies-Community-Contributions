package com.cg.healthreminder.controller;

// Author: Naman Bhandari

import com.cg.healthreminder.model.Patient;
import com.cg.healthreminder.services.PatientService;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mockito;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.WebMvcTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.mock.web.MockHttpServletResponse;
import org.springframework.test.context.junit4.SpringRunner;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.MvcResult;
import org.springframework.test.web.servlet.request.MockMvcRequestBuilders;

import static org.assertj.core.api.Assertions.assertThat;

import java.util.ArrayList;
import java.util.List;

@RunWith(SpringRunner.class)
@WebMvcTest(value = PatientController.class)
public class PatientControllerTest {
	@Autowired
	private MockMvc mockMvc;
	
	@MockBean
	private PatientService patientService;
	
	/**
     * Convert Object into Json String by using Jackson ObjectMapper
     * @param appointmentDetails
     * @return
     * @throws JsonProcessingException
     */
    private String converttoJson(Object patient) throws JsonProcessingException {
        ObjectMapper objectMapper = new ObjectMapper();
        return objectMapper.writeValueAsString(patient);
    }
    @Test
    public void testNewPatient() throws Exception{
    	String URI = "/healthreminder/patient";
    	Patient pt = new Patient();
    	pt.setPatientId(100);
		pt.setPatientEmail("trial@trial.com");
		pt.setPatientMobile("1234567890");
		pt.setPatientName("qwerty");
		pt.setPatientAge(1);
		pt.setPatientHeight(1.0);
		pt.setPatientWeight(1.0);
		String jsonInput = this.converttoJson(pt);
		
		Mockito.when(patientService.addPatient(Mockito.any(Patient.class))).thenReturn(pt);    
		
		MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.post(URI).accept(MediaType.APPLICATION_JSON)
				.content(jsonInput).contentType(MediaType.APPLICATION_JSON)).andReturn();
		MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
        String jsonOutput = mockHttpServletResponse.getContentAsString();
        assertThat(jsonInput).isEqualTo(jsonOutput);
        Assert.assertEquals(HttpStatus.OK.value(), mockHttpServletResponse.getStatus());
    }
    
    @Test
    public void testGetAllPatients() throws Exception{
    	String URI = "/healthreminder/patients";
    	Patient pt1 = new Patient();
    	pt1.setPatientId(100);
		pt1.setPatientEmail("trial@trial.com");
		pt1.setPatientMobile("1234567890");
		pt1.setPatientName("qwerty");
		pt1.setPatientAge(1);
		pt1.setPatientHeight(1.0);
		pt1.setPatientWeight(1.0);
		
		Patient pt2 = new Patient();
    	pt2.setPatientId(200);
		pt2.setPatientEmail("trial1@trial.com");
		pt2.setPatientMobile("1234567890");
		pt2.setPatientName("qwerty");
		pt2.setPatientAge(1);
		pt2.setPatientHeight(1.0);
		pt2.setPatientWeight(1.0);
		
		List<Patient> plst= new ArrayList<>();
		plst.add(pt1);
		plst.add(pt2);
		
		String jsonInput= this.converttoJson(plst);
		 Mockito.when(patientService.getAllPatients()).thenReturn(plst);
	        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.get(URI).accept(MediaType.APPLICATION_JSON)).andReturn();
	        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
	        String jsonOutput = mockHttpServletResponse.getContentAsString();

	        assertThat(jsonInput).isEqualTo(jsonOutput);
    }
    
    @Test
    public void testUpdatePatient() throws Exception{
    	String URI="/healthreminder/patient/{id}";
    	Patient pt = new Patient();
    	pt.setPatientId(100);
		pt.setPatientEmail("trial@trial.com");
		pt.setPatientMobile("1234567890");
		pt.setPatientName("qwerty");
		pt.setPatientAge(1);
		pt.setPatientHeight(1.0);
		pt.setPatientWeight(1.0);
		
		
	        Mockito.when(patientService.deletePatientById(Mockito.anyInt())).thenReturn(pt.getPatientId());
	        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.delete(URI,1).accept(MediaType.
	        		APPLICATION_JSON)).andReturn();
	        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();

	        Assert.assertEquals(HttpStatus.OK.value(), mockHttpServletResponse.getStatus());
    }
    
}
