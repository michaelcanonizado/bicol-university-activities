package org.PayrollForm;

public class FreelancerPayrollForm {
    private String freelancerName;
    private double hourlyRate;
    private double hoursWorked;
    private double grossIncome;

    public FreelancerPayrollForm (String freelancerName, double hourlyRate) {
        this.freelancerName = freelancerName;
        this.hourlyRate = hourlyRate;

        this.hoursWorked = 0.0;
        this.grossIncome = 0.0;
    }

}
