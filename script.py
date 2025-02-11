import requests
import datetime

# Notion API Token and Database ID
NOTION_TOKEN = "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"
DATABASE_ID = "196e48bbe7fe806dbad1e6968a6ba916"
HEADERS = {
    "Authorization": f"Bearer {NOTION_TOKEN}",
    "Content-Type": "application/json",
    "Notion-Version": "2022-06-28",
}

# Function to fetch pages from Notion database
def fetch_database_pages():
    url = f"https://api.notion.com/v1/databases/{DATABASE_ID}/query"
    response = requests.post(url, headers=HEADERS)
    return response.json().get("results", [])

# Function to update Event Date in Notion
def update_event_date(page_id, start_datetime, end_datetime):
    url = f"https://api.notion.com/v1/pages/{page_id}"
    data = {
        "properties": {
            "Event Date": {
                "date": {
                    "start": start_datetime.isoformat(),
                    "end": end_datetime.isoformat(),
                    "time_zone": "Europe/Luxembourg"
                }
            }
        }
    }
    requests.patch(url, headers=HEADERS, json=data)

# Main script
def main():
    pages = fetch_database_pages()
    for page in pages:
        props = page["properties"]
        
        date_str = props["Date"].get("date", {}).get("start")
        start_time_str = props["Start Time"].get("rich_text", [{}])[0].get("text", {}).get("content", "")
        duration_min = props["Duration"].get("number", 0)
        
        if not date_str or not start_time_str:
            continue
        
        start_datetime = datetime.datetime.strptime(f"{date_str} {start_time_str}", "%Y-%m-%d %H:%M")
        end_datetime = start_datetime + datetime.timedelta(minutes=duration_min)
        
        update_event_date(page["id"], start_datetime, end_datetime)

if __name__ == "__main__":
    main()
