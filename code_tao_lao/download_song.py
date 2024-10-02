from pytube import YouTube
from googleapiclient.discovery import build
import os

# Replace with your actual YouTube Data API key
YOUTUBE_API_KEY = "AIzaSyAB5zzoxl7VEjIgb3JE3SzXJM6YbIUuD9U"

# Initialize the YouTube API client
youtube = build('youtube', 'v3', developerKey=YOUTUBE_API_KEY)

def search_youtube(song_title):
    # Search for the song on YouTube
    request = youtube.search().list(
        q=song_title,
        part="snippet",
        type="video",
        maxResults=1
    )
    response = request.execute()

    # Get the first video result
    if response['items']:
        video_id = response['items'][0]['id']['videoId']
        video_url = f"https://www.youtube.com/watch?v={video_id}"
        print(f"Found video for '{song_title}': {video_url}")
        return video_url
    else:
        print(f"No results found for '{song_title}'")
        return None

def download_mp3(youtube_url, download_path):
    try:
        yt = YouTube(youtube_url)
        audio_stream = yt.streams.filter(only_audio=True).first()
        print(f"Downloading: {yt.title}")
        
        # Downloading the audio
        out_file = audio_stream.download(output_path=download_path)
        # Saving the file as an MP3
        base, ext = os.path.splitext(out_file)
        new_file = base + '.mp3'
        os.rename(out_file, new_file)
        
        print(f"Downloaded and converted to MP3: {new_file}")
    except Exception as e:
        print(f"An error occurred: {e}")

# List of song titles
song_titles = [
    "Shape of You",
    # Add more song titles here
]

# Specify the download directory
download_directory = "./downloads"

# Ensure the download directory exists
os.makedirs(download_directory, exist_ok=True)

# Search and download each song as MP3
for song in song_titles:
    video_url = search_youtube(song)
    if video_url:
        download_mp3(video_url, download_directory)
