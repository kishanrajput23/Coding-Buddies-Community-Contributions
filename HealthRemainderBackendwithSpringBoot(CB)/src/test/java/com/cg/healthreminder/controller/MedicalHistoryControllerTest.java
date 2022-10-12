package com.cg.healthreminder.controller;

//Author: Naman Bhandari

import com.cg.healthreminder.model.MedicalHistory;
import com.cg.healthreminder.services.MedicalHistoryService;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mockito;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.WebMvcTest;
import org.springframework.boot.test.mock.mockito.MockBean;
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
@WebMvcTest(value = MedicalHistoryController.class)
public class MedicalHistoryControllerTest {
	@Autowired
	private MockMvc mockMvc;
	
	@MockBean
	private MedicalHistoryService medicalHistoryService;
	
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
    public void testNewMedicalHistory() throws Exception{
    	String URI="/healthreminder/addrecord";
    	MedicalHistory mh = new MedicalHistory();
    	mh.setFile("file name");
    	mh.setPatientId(1);
    	mh.setNotes("sample notes");
    	String jsonInput = this.converttoJson(mh);
		
		Mockito.when(medicalHistoryService.addRecord(Mockito.any(MedicalHistory.class))).thenReturn(mh);    
		
		MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.post(URI).accept(MediaType.APPLICATION_JSON).content(jsonInput).contentType(MediaType.APPLICATION_JSON))
                .andReturn();
		MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
        String jsonOutput = mockHttpServletResponse.getContentAsString();

        assertThat(jsonInput).isEqualTo(jsonOutput);
    }
    
    @Test
    public void testFindRecordByPatientId() throws Exception{
    	String URI="/healthreminder/records/{id}";
    	MedicalHistory mh = new MedicalHistory();
    	mh.setFile("file name");
    	mh.setPatientId(1);
    	mh.setNotes("sample notes");
    	List<MedicalHistory> mhlst = new ArrayList<>();
    	mhlst.add(mh);
    	String jsonInput = this.converttoJson(mhlst);
    	
    	Mockito.when(medicalHistoryService.getByPatientId(Mockito.anyInt())).thenReturn(mhlst);
        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.get(URI, 1).accept(MediaType.APPLICATION_JSON))
                .andReturn();
        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
        String jsonOutput = mockHttpServletResponse.getContentAsString();

        assertThat(jsonInput).isEqualTo(jsonOutput);
    }
    
    @Test
    public void testUpdateRecord() throws Exception{
    	String URI="/healthreminder/record";
    	MedicalHistory mh = new MedicalHistory();
    	mh.setFile("file name");
    	mh.setPatientId(1);
    	mh.setNotes("sample notes");
    	//Update 
    	mh.setNotes("new sample notes");
    	String jsonInput = this.converttoJson(mh);
    	Mockito.when(medicalHistoryService.updateRecord(Mockito.any(MedicalHistory.class))).thenReturn(mh);
        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.put(URI).accept(MediaType.APPLICATION_JSON).content(jsonInput).contentType(MediaType.APPLICATION_JSON))
                .andReturn();
        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
        String jsonOutput = mockHttpServletResponse.getContentAsString();

        assertThat(jsonInput).isEqualTo(jsonOutput);
    }
}
