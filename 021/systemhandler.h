#include <fcntl.h>
#include <unistd.h>

class FileHandle {
private:
    int m_fd;
    /* open file and holding FILE pointer ************************

        int open (const char *filepath, int flag);
        int open (const char *filepath, int flag, mode_t mode);

        O_RDONLY        読取り専用でオープン
		O_WRONLY        書込み専用でオープン
		O_RDWR          読取りと書込み用にオープン
		O_NONBLOCK      オープンするときにブロックしない
		O_APPEND        書込みのたびに末尾に追加する
		O_CREAT         ファイルが存在しない場合、作成する
		O_TRUNC         サイズを 0 に切り捨てる
		O_EXCL          作成するファイルが既に存在した場合、エラーとする
		O_SHLOCK        共有ロックを不可分に取得する
		O_EXLOCK        排他的ロックを不可分に取得する
		O_DIRECT        キャッシュの効果を無くすまたは減らす
		O_FSYNC         同期的に書き込む
		O_NOFOLLOW      シンボリックリンクを辿らない

    ****************************************************************/
    
public:
    FileHandle();
    FileHandle(const char* path, const int flag = O_RDONLY);
    FileHandle(FileHandle && other) noexcept;
    ~FileHandle();

    /* Return the file discriptor (m_fd) */
    int get() const noexcept;

    /* Return the file discriptor (m_fd) and reset m_fd */
    int release() noexcept;

    /* validate handle */
    /* https://cpprefjp.github.io/lang/cpp11/explicit_conversion_operator.html */
    explicit operator bool() const;

    /* move handle */
    
};