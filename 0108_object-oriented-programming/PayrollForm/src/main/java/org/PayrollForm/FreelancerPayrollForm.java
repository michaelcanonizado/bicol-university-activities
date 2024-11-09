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

    public String getFreelancerName() {
        return freelancerName;
    }

    public double getHourlyRate() {
        return hourlyRate;
    }

    public void setFreelancerName(String freelancerName) {
        this.freelancerName = freelancerName;
    }

    public void setHourlyRate(double hourlyRate) {
        this.hourlyRate = hourlyRate;
    }
}
