#!/bin/bash
gcc -o travel_budget main.c choose_categories.c budget_allotment.c expense_record.c budget_monitor.c fund_track.c final_report.c
echo "Build complete. Run with ./travel_budget"