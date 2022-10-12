/**
 * @AnkitBanerjee
 * 
 * This is the Controller Testing Class for Alarm Module.
*/

package com.cg.healthreminder.controller;

import com.cg.healthreminder.model.AlarmModule;
import com.cg.healthreminder.services.AlarmModuleService;
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


@RunWith(SpringRunner.class)
@WebMvcTest(value = AlarmModuleController.class)
public class AlarmModuleControllerTest {
	
	@Autowired
    private MockMvc mockMvc;

    @MockBean
    private AlarmModuleService alarmModuleService;
    
    
    /**
     * Convert Object into Json String by using Jackson ObjectMapper
     * @param alarm
     * @return
     * @throws JsonProcessingException
     */
    private String converttoJson(Object alarm) throws JsonProcessingException {
        ObjectMapper objectMapper = new ObjectMapper();
        return objectMapper.writeValueAsString(alarm);
    }
    
    /**
	 * 
	 * To check if a new Alarm Module gets created
	*/
    @Test
    public void testNewAlarmModule() throws Exception{
        String URI = "/alarm/createAlarm";
        AlarmModule alarm= new AlarmModule();
        alarm.setPatientId(102);
        alarm.setAlarmName("Body Pain Medicine");
        alarm.setAlarmDate(null);//Date.valueOf("2019-08-15")
        alarm.setAlarmTime(null);//Timestamp.valueOf("2019-08-15T10:18:19");
        alarm.setAlarmNotes("Take the medicine after lunch");
        String jsonInput = this.converttoJson(alarm);

        Mockito.when(alarmModuleService.createAlarm(Mockito.any(AlarmModule.class))).thenReturn(alarm);
        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.post(URI).accept(MediaType.APPLICATION_JSON).content(jsonInput).contentType(MediaType.APPLICATION_JSON))
                .andReturn();
        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
        String jsonOutput = mockHttpServletResponse.getContentAsString();
        assertThat(jsonInput).isEqualTo(jsonOutput);
        Assert.assertEquals(HttpStatus.OK.value(), mockHttpServletResponse.getStatus());
    }
    
    /**
	 * 
	 * To check if we able to find Alarm Module
	*/
    @Test
    public void testFindAlarmById() throws Exception{
        String URI = "/alarm/getAlarmById/{alarmId}";
        AlarmModule alarm= new AlarmModule();
        alarm.setPatientId(102);
        alarm.setAlarmName("Body Pain Medicine");
        alarm.setAlarmDate(null);
        alarm.setAlarmTime(null);
        alarm.setAlarmNotes("Take the medicine after lunch");

		String jsonInput = this.converttoJson(alarm);

        Mockito.when(alarmModuleService.findAlarmById(Mockito.anyInt())).thenReturn(alarm);
        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.get(URI, 102).accept(MediaType.APPLICATION_JSON))
                .andReturn();
        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
        String jsonOutput = mockHttpServletResponse.getContentAsString();

        assertThat(jsonInput).isEqualTo(jsonOutput);
    }
    
    /**
	 * 
	 * To check if we able to delete Alarm Module
	*/
    @Test
    public void testDeleteAlarmById() throws Exception{
    	 String URI = "/alarm/deleteAlarmById/alarm/{alarmId}";  
    	 AlarmModule alarm= new AlarmModule();
         alarm.setPatientId(102);
         alarm.setAlarmName("Body Pain Medicine");
         alarm.setAlarmDate(null);
         alarm.setAlarmTime(null);
         alarm.setAlarmNotes("Take the medicine after lunch");

        Mockito.when(alarmModuleService.findAlarmById(Mockito.anyInt())).thenReturn(alarm);
        Mockito.when(alarmModuleService.deleteAlarmById(Mockito.anyInt())).thenReturn(alarm);
        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.delete(URI,102).accept(MediaType.
        		APPLICATION_JSON)).andReturn();
        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();

        Assert.assertEquals(HttpStatus.OK.value(), mockHttpServletResponse.getStatus());

    }
    
    
//    @Test
//    public void testUpdateByAlarmId() throws Exception{
//        String URI = "/alarm/updateAlarmbyId/{alarmId}/{patientId}/{alarmName}/{alarmTime}/{alarmDate}/{alarmNotes}";
//        AlarmModule alarm= new AlarmModule();
//        alarm.setAlarmId(201);
//        alarm.setPatientId(192);
//        alarm.setAlarmName("Body Pain Medicine");
//        alarm.setAlarmDate(null);
//        alarm.setAlarmTime(null);
//        alarm.setAlarmNotes("Take the medicine after lunch");
//
//        String jsonInput = this.converttoJson(alarm);
//
//        Mockito.when(alarmModuleService.updateAlarmById(Mockito.anyInt(), Mockito.anyInt(), Mockito.anyString(), null, null, Mockito.anyString())).thenReturn(alarm);
//        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.put(URI, 201, 192, "Body Pain Medicine", null, null, "Take the medicine after lunch").accept(MediaType.APPLICATION_JSON).content(jsonInput).contentType(MediaType.APPLICATION_JSON))
//                .andReturn();
//        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
//        String jsonOutput = mockHttpServletResponse.getContentAsString();
//
//        assertThat(jsonInput).isEqualTo(jsonOutput);
//    }
    

}
