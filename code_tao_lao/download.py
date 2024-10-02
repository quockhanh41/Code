from pytube import YouTube

def download_video(youtube_url, download_path):
    try:
        # Create a YouTube object
        yt = YouTube(youtube_url)
        
        # Print the title of the video
        print(f"Title: {yt.title}")
        
        # Get the highest resolution stream
        video_stream = yt.streams.get_highest_resolution()
        
        # Download the video
        print(f"Downloading: {yt.title}")
        video_stream.download(output_path=download_path)
        print(f"Downloaded to: {download_path}")
    except Exception as e:
        print(f"An error occurred: {e}")

# Replace this with your YouTube video URL
youtube_url = "https://www.youtube.com/watch?v=0zdaS6qvmWY"

# Specify the download directory
download_directory = "./downloads"

# Download the video
download_video(youtube_url, download_directory)
